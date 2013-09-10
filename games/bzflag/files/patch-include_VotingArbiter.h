--- ./include/VotingArbiter.h.orig	2012-07-16 03:32:02.000000000 +0400
+++ ./include/VotingArbiter.h	2013-09-11 02:18:23.000000000 +0400
@@ -230,12 +230,11 @@
 
 };
 
-
-inline VotingArbiter::VotingArbiter(unsigned short int voteTime=60,
-				    unsigned short int vetoTime=20,
-				    unsigned short int votesRequired=2,
-				    float votePercentage=50.1,
-				    unsigned short int voteRepeatTime=300)
+inline VotingArbiter::VotingArbiter(unsigned short int voteTime,
+				    unsigned short int vetoTime,
+				    unsigned short int votesRequired,
+				    float votePercentage,
+				    unsigned short int voteRepeatTime)
   : _votingBooth(NULL),
     _maxVotes(votesRequired+1),
     _voteTime(voteTime),
