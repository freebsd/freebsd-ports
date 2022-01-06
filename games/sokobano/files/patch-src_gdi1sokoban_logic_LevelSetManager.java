--- src/gdi1sokoban/logic/LevelSetManager.java.orig	2009-03-26 21:46:48 UTC
+++ src/gdi1sokoban/logic/LevelSetManager.java
@@ -191,7 +191,11 @@ public class LevelSetManager extends IdentifierManager
 		try {
 			DocumentBuilderFactory dbfac = DocumentBuilderFactory.newInstance();
 			DocumentBuilder docBuilder = dbfac.newDocumentBuilder();
-			Document doc = docBuilder.parse(new File(_lvlSetPath+levelSetId+File.separator+"highScores.xml"));
+			String path = System.getProperty("user.home") +
+			    File.separator + ".config" + File.separator +
+			    "sokobano" + File.separator;
+			Document doc = docBuilder.parse(new File(path +
+			    levelSetId + "-highScores.xml"));
 
 			Node first = doc.getFirstChild();
 			NodeList levelNodes = doc.getElementsByTagName("level");
@@ -268,7 +272,9 @@ public class LevelSetManager extends IdentifierManager
 			// If statistics have changed, write back to file:
 			if (isAdded) {
 				OutputFormat format = new OutputFormat(doc);
-				FileOutputStream fileOut = new FileOutputStream(_lvlSetPath + levelSetId + File.separator + "highScores.xml");
+				FileOutputStream fileOut = new
+				    FileOutputStream(path + levelSetId +
+				    "-highScores.xml");
 				XMLSerializer ser = new XMLSerializer(fileOut,format);
 				ser.serialize(doc.getDocumentElement());
 				fileOut.close();
@@ -294,7 +300,12 @@ public class LevelSetManager extends IdentifierManager
 			try{
 				DocumentBuilderFactory dbfac = DocumentBuilderFactory.newInstance();
 				DocumentBuilder docBuilder = dbfac.newDocumentBuilder();
-				Document doc = docBuilder.parse(new File(_lvlSetPath+i.getId()+File.separator+"highScores.xml"));
+				String path = System.getProperty("user.home") +
+				    File.separator + ".config" +
+				    File.separator + "sokobano" +
+				    File.separator;
+				Document doc = docBuilder.parse(new File(
+				    path + i.getId() + "-highScores.xml"));
 				NodeList playerStatNameList = doc.getElementsByTagName("PlayerStatistic");
 				//Node first =doc.getFirstChild();
 				ArrayList<Node> nodeToDelete = new ArrayList<Node>();
@@ -313,7 +324,9 @@ public class LevelSetManager extends IdentifierManager
 				}
 
 				OutputFormat format = new OutputFormat(doc);
-				FileOutputStream outputFile =new FileOutputStream(_lvlSetPath+i.getId()+File.separator+"highScores.xml");
+				FileOutputStream outputFile = new
+				    FileOutputStream(path + i.getId() +
+				    "-highScores.xml");
 				XMLSerializer ser = new XMLSerializer(outputFile,format);
 				ser.serialize(doc.getDocumentElement());
 				outputFile.close();
@@ -338,7 +351,10 @@ public class LevelSetManager extends IdentifierManager
 		try{
 			DocumentBuilderFactory dbfac = DocumentBuilderFactory.newInstance();
 			DocumentBuilder docBuilder = dbfac.newDocumentBuilder();
-			Document doc = docBuilder.parse(new File(_lvlSetPath+id+File.separator+"highScores.xml"));
+			Document doc = docBuilder.parse(new File(
+			    System.getProperty("user.home") + File.separator +
+			    ".config" + File.separator + "sokobano" +
+			    File.separator + id + "-highScores.xml"));
 
 			NodeList levelNameList = doc.getElementsByTagName("level");
 			//int currId
