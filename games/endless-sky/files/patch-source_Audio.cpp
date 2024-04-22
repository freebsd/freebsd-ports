--- source/Audio.cpp.orig	2023-10-21 20:01:54 UTC
+++ source/Audio.cpp
@@ -82,7 +82,7 @@ namespace {
 	// This queue keeps track of sounds that have been requested to play. Each
 	// added sound is "deferred" until the next audio position update to make
 	// sure that all sounds from a given frame start at the same time.
-	map<const Sound *, QueueEntry> queue;
+	map<const Sound *, QueueEntry> queue_;
 	map<const Sound *, QueueEntry> deferred;
 	thread::id mainThreadID;
 
@@ -249,7 +249,7 @@ void Audio::Update(const Point &listenerPosition)
 	listener = listenerPosition;
 
 	for(const auto &it : deferred)
-		queue[it.first].Add(it.second);
+		queue_[it.first].Add(it.second);
 	deferred.clear();
 }
 
@@ -273,7 +273,7 @@ void Audio::Play(const Sound *sound, const Point &posi
 	// Place sounds from the main thread directly into the queue. They are from
 	// the UI, and the Engine may not be running right now to call Update().
 	if(this_thread::get_id() == mainThreadID)
-		queue[sound].Add(position - listener);
+		queue_[sound].Add(position - listener);
 	else
 	{
 		unique_lock<mutex> lock(audioMutex);
@@ -317,12 +317,12 @@ void Audio::Step()
 	{
 		if(source.GetSound()->IsLooping())
 		{
-			auto it = queue.find(source.GetSound());
-			if(it != queue.end())
+			auto it = queue_.find(source.GetSound());
+			if(it != queue_.end())
 			{
 				source.Move(it->second);
 				newSources.push_back(source);
-				queue.erase(it);
+				queue_.erase(it);
 			}
 			else
 			{
@@ -367,7 +367,7 @@ void Audio::Step()
 
 	// Now, what is left in the queue is sounds that want to play, and that do
 	// not correspond to an existing source.
-	for(const auto &it : queue)
+	for(const auto &it : queue_)
 	{
 		// Use a recycled source if possible. Otherwise, create a new one.
 		unsigned source = 0;
@@ -396,7 +396,7 @@ void Audio::Step()
 		sources.back().Move(it.second);
 		alSourcePlay(source);
 	}
-	queue.clear();
+	queue_.clear();
 
 	// Queue up new buffers for the music, if necessary.
 	int buffersDone = 0;
