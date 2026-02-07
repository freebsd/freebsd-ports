
#define GLOBAL_SETENV \
  setenv("R_USER", ::getenv("HOME"), 0); \
  setenv("R_HOME", "%%PREFIX%%/lib/R", 0); \
  setenv("R_INCLUDE_DIR", "%%PREFIX%%/lib/R/include", 0); \
  setenv("R_LIBS", "%%PREFIX%%/lib/R", 0); \
  setenv("R_DOC_DIR", "%%PREFIX%%/share/doc/R", 0);
