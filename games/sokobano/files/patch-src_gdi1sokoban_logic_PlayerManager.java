--- src/gdi1sokoban/logic/PlayerManager.java.orig	2009-03-26 21:46:56 UTC
+++ src/gdi1sokoban/logic/PlayerManager.java
@@ -46,7 +46,10 @@ public class PlayerManager extends IdentifierManager{
 
 
 	//path to player resource directory
-	private String _playerPath ="res"+File.separator+"player"+File.separator;
+	private static final String _playerPath =
+	    System.getProperty("user.home") + File.separator + ".config" +
+	    File.separator + "sokobano" + File.separator + "player" +
+	    File.separator;
 	//HashMap of LevelStatistic for given player and level set
 	private HashMap<Integer,LevelStatistic> _levelSetStatistic = null;
 	//level set id of last statistic, that have been loaded  
@@ -77,7 +80,7 @@ public class PlayerManager extends IdentifierManager{
 	 * Singleton constructor that  sets the path to players.xml
 	 */
 	private PlayerManager(){
-		super("res"+File.separator+"player"+File.separator+"players.xml");
+		super(_playerPath + "players.xml");
 		_playerIdentifiers = new ArrayList<PlayerIdentifier>();
 		for(IdentifierRecord i : _identifierRecords){
 			_playerIdentifiers.add(new PlayerIdentifier(i.getName(), i.getId(), i.getUri()));
