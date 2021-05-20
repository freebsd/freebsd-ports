# Created by: Palle Girgensohn <girgen@partitur.se>

WANT_PGSQL_VER=	10

INSTALL_DIRS=	src/pl/plperl contrib/hstore_plperl

# this port fails to build in parallel
MAKE_JOBS_UNSAFE=	yes

.include "${.CURDIR}/../postgresql14-plperl/Makefile"
