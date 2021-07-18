WANT_PGSQL_VER=	10

INSTALL_DIRS=	src/pl/plpython contrib/hstore_plpython contrib/ltree_plpython

# this port fails to build in parallel
MAKE_JOBS_UNSAFE=	yes

.include "${.CURDIR}/../postgresql14-plpython/Makefile"
