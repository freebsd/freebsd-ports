Index: src/herotemplates.cpp
@@ -64,15 +64,6 @@
 
 int HeroTemplates::loadHeroTemplates()
 {
-  FILE *fileptr = fopen (File::getMiscFile("heronames").c_str(), "r");
-  char *line = NULL;
-  size_t len = 0;
-  ssize_t read;
-  int retval;
-  int gender;
-  int side;
-  size_t bytesread = 0;
-  char *tmp;
   const Armysetlist* al = Armysetlist::getInstance();
   const Army* herotype;
 
@@ -83,48 +74,37 @@
     {
       const Army *a = al->getArmy (p->getArmyset(), j);
       if (a->isHero())
-	heroes.push_back(a);
+		heroes.push_back(a);
     }
+ 
+  std::ifstream file(File::getMiscFile("heronames").c_str());
 
-  if (fileptr == NULL)
-    return -1;
-  while ((read = getline (&line, &len, fileptr)) != -1)
-    {
-      bytesread = 0;
-      retval = sscanf (line, "%d%d%n", &side, &gender, &bytesread);
-      if (retval != 2)
-	{
-	  free (line);
-	  return -2;
-	}
-      while (isspace(line[bytesread]) && line[bytesread] != '\0')
-	bytesread++;
-      tmp = strchr (&line[bytesread], '\n');
-      if (tmp)
-	tmp[0] = '\0';
-      if (strlen (&line[bytesread]) == 0)
-	{
-	  free (line);
-	  return -3;
-	}
-      if (side < 0 || side > (int) MAX_PLAYERS)
-	{
-	  free (line);
-	  return -4;
+  if (file.good()) {
+	std::string buffer, name;
+	int side, gender;
+
+	while (std::getline(file, buffer)) {
+	std::istringstream line(buffer);
+	if (!(line >> side >> gender >> name))
+		return -2;
+
+	if (side < 0 || side > (int) MAX_PLAYERS)
+		return -4;
+
+	herotype = heroes[rand() % heroes.size()];
+	Hero *newhero = new Hero (*herotype, "", NULL);
+
+	if (gender)
+		newhero->setGender(Hero::MALE);
+	else
+		newhero->setGender(Hero::FEMALE);
+
+	newhero->setName (name);
+    d_herotemplates[side].push_back (newhero);
 	}
+  } else
+	return -1;
 
-      herotype = heroes[rand() % heroes.size()];
-      Hero *newhero = new Hero (*herotype, "", NULL, true);
-      if (gender)
-	newhero->setGender(Hero::MALE);
-      else
-	newhero->setGender(Hero::FEMALE);
-      newhero->setName (&line[bytesread]);
-      d_herotemplates[side].push_back (newhero);
-    }
-  if (line)
-    free (line);
-  fclose (fileptr);
+  file.close();
   return 0;
 }
-        
