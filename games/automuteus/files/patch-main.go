--- main.go.orig	2020-12-29 06:50:50 UTC
+++ main.go
@@ -43,10 +43,14 @@ func main() {
 func discordMainWrapper() error {
 	err := godotenv.Load("final.txt")
 	if err != nil {
-		err = godotenv.Load("config.txt")
+		cfn := os.Getenv("CONFIG_PATH")
+		if cfn == "" {
+			cfn = "config.txt"
+		}
+		err = godotenv.Load(cfn)
 		if err != nil && os.Getenv("DISCORD_BOT_TOKEN") == "" {
 			log.Println("Can't open config file and missing DISCORD_BOT_TOKEN; creating config.txt for you to use for your config")
-			f, err := os.Create("config.txt")
+			f, err := os.Create(cfn)
 			if err != nil {
 				log.Println("Issue creating sample config.txt")
 				return err
