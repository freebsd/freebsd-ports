--- src/http.h
+++ src/http.h
@@ -44,6 +44,7 @@
 int print_http_variable (vartree_t *request_vars, const char *name, connection_t *clicon, int fd);
 char *url_encode(const char *string, char **result_p);
 char *url_decode (const char *string);
+char *html_escape(const char *string);
 const char *parse_template_file (connection_t *clicon, connection_t *sourcecon, const char *ptr, int fd, vartree_t *variables);
 int write_template_parsed_html_page (connection_t *clicon, connection_t *sourcecon, const char *template_file, int fd, vartree_t *variables);
 const char *http_loop_sources (char *ident, connection_t *clicon, const char *ptr, int fd, vartree_t *variables);
