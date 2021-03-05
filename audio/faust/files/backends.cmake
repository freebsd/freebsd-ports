# backends.cmake is recommended by the upstream: https://github.com/grame-cncm/faust/wiki/backends

# Below COMPILER,STATIC,DYNAMIC keywords can be enabled.
# However, we disabled static libs in Makefile, so STATIC isn't used.

set (C_BACKEND      COMPILER DYNAMIC  CACHE STRING  "Include C backend"           FORCE)
set (CPP_BACKEND    COMPILER DYNAMIC  CACHE STRING  "Include CPP backend"         FORCE)
set (LLVM_BACKEND   COMPILER DYNAMIC  CACHE STRING  "Include LLVM backend"        FORCE)
#set (ASMJS_BACKEND  ASMJS                    CACHE STRING  "Include ASMJS backend"       FORCE)
#set (INTERP_BACKEND OFF                      CACHE STRING  "Include INTERPRETER backend" FORCE)

