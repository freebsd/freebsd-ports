--- src/gdi1sokoban/logic/LevelManager.java.orig	2009-03-26 21:46:34 UTC
+++ src/gdi1sokoban/logic/LevelManager.java
@@ -168,7 +168,11 @@ public class LevelManager extends IdentifierManager{
 		try{
 			DocumentBuilderFactory dbfac = DocumentBuilderFactory.newInstance();
 			DocumentBuilder docBuilder = dbfac.newDocumentBuilder();
-			Document doc = docBuilder.parse(new File("res"+File.separator+"levelSet"+File.separator+_levelSetId+File.separator+"highScores.xml"));
+			String path = System.getProperty("user.home") +
+			    File.separator + ".config" + File.separator +
+			    "sokobano" + File.separator;
+			Document doc = docBuilder.parse(new File(path +
+			    _levelSetId + "-highScores.xml"));
 			NodeList levelList = doc.getElementsByTagName("level");
 			for (int i = 0; i < levelList.getLength(); i++) {
 				Node tmp = levelList.item(i);
@@ -181,7 +185,8 @@ public class LevelManager extends IdentifierManager{
 				}
 			}
 			OutputFormat format = new OutputFormat(doc);
-			FileOutputStream outputFile =new FileOutputStream("res"+File.separator+"levelSet"+File.separator+_levelSetId+File.separator+"highScores.xml");
+			FileOutputStream outputFile = new FileOutputStream(
+			    path + _levelSetId + "-highScores.xml");
 			XMLSerializer ser = new XMLSerializer(outputFile,format);
 			ser.serialize(doc.getDocumentElement());
 			outputFile.close();
