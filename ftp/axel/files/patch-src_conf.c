- workaround for https://github.com/axel-download-accelerator/axel/issues/399

--- src/conf.c.orig	2023-01-22 20:28:48 UTC
+++ src/conf.c
@@ -276,7 +276,7 @@ conf_init(conf_t *conf)
 		      "User-Agent", DEFAULT_USER_AGENT);
 	conf->add_header_count = HDR_count_init;
 
-	conf->interfaces = calloc(1, sizeof(if_t));
+	conf->interfaces = calloc(1, sizeof(if_t_));
 	if (!conf->interfaces)
 		return 0;
 
@@ -329,11 +329,11 @@ int
 parse_interfaces(conf_t *conf, char *s)
 {
 	char *s2;
-	if_t *iface;
+	if_t_ *iface;
 
 	iface = conf->interfaces->next;
 	while (iface != conf->interfaces) {
-		if_t *i;
+		if_t_ *i;
 
 		i = iface->next;
 		free(iface);
@@ -342,7 +342,7 @@ parse_interfaces(conf_t *conf, char *s)
 	free(conf->interfaces);
 
 	if (!*s) {
-		conf->interfaces = calloc(1, sizeof(if_t));
+		conf->interfaces = calloc(1, sizeof(if_t_));
 		if (!conf->interfaces)
 			return 0;
 
@@ -350,7 +350,7 @@ parse_interfaces(conf_t *conf, char *s)
 		return 1;
 	}
 
-	conf->interfaces = iface = malloc(sizeof(if_t));
+	conf->interfaces = iface = malloc(sizeof(if_t_));
 	if (!conf->interfaces)
 		return 0;
 
@@ -365,7 +365,7 @@ parse_interfaces(conf_t *conf, char *s)
 			strlcpy(iface->text, s, sizeof(iface->text));
 		s = s2 + 1;
 		if (*s) {
-			iface->next = malloc(sizeof(if_t));
+			iface->next = malloc(sizeof(if_t_));
 			if (!iface->next)
 				return 0;
 
