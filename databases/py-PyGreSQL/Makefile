# Ports collection Makefile for:	PyGreSQL
# Version required:			2.1
# Date created:				6/25/1998
# Whom:					n@nectar.com
#
# $Id: Makefile,v 1.4 1998/07/20 11:41:31 asami Exp $
#

DISTNAME=		PyGreSQL-2.1
PKGNAME=		py-PyGreSQL-2.1
CATEGORIES=		databases
MASTER_SITES=		ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=		.tgz

MAINTAINER=		n@nectar.com

BUILD_DEPENDS=		python:${PORTSDIR}/lang/python
RUN_DEPENDS=		python:${PORTSDIR}/lang/python
LIB_DEPENDS=		pq\\.1\\.:${PORTSDIR}/databases/postgresql

WRKSRC=			${WRKDIR}
HAS_CONFIGURE=		YES
GNU_CONFIGURE=		YES

PY_PREFIX=		python -c "import sys; print sys.prefix"
PY_EXEC_PREFIX=		python -c "import sys; print sys.exec_prefix"
PY_SITE_PYTHON=		python -c "import sys; import string; print (filter(lambda a: string.find(a, 'site-python') >= 0, sys.path) or [''])[0]"

CHOWN?=			chown
CHMOD?=			chmod

do-configure:
.if defined(BATCH)
	@(if [ "`${PY_SITE_PYTHON}`" = "" ]; then               \
	${MKDIR} ${PREFIX}/lib/site-python;                     \
	${CHOWN} ${BINOWN}.${BINGRP} ${PREFIX}/lib/site-python; \
	${CHMOD} ${BINMODE} ${PREFIX}/lib/site-python;          \
	fi)
.else
	@(if [ "`${PY_SITE_PYTHON}`" = "" ]; then                          \
	${ECHO} "You must create a site-python directory in order to";     \
	${ECHO} "build and install this port.  On most systems, creating"; \
	${ECHO} "a directory called ${PREFIX}/lib/site-python will do.";   \
	exit 1;                                                            \
	fi)
.endif
.for f in Makefile Makefile.in configure.in
	${CP} ${SCRIPTDIR}/${f} ${WRKSRC}
.endfor
	${INSTALL} -c -m 0555 ${SCRIPTDIR}/install-sh ${WRKSRC}
	${INSTALL} -c -m 0555 ${SCRIPTDIR}/configure.local ${WRKSRC}/configure
	@(cd ${WRKSRC} && CC="${CC}" CXX="${CXX}" ac_cv_path_CC="${CC}" \
	CFLAGS="${CFLAGS}" \
	INSTALL="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}" \
	INSTALL_DATA="${INSTALL_DATA}"       \
	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	INSTALL_SCRIPT="${INSTALL_SCRIPT}"   \
	PY_EXEC_PREFIX=`${PY_EXEC_PREFIX}`   \
	PY_SITE_PYTHON=`${PY_SITE_PYTHON}`   \
	LDFLAGS="-L`${PY_PREFIX}`/lib/python1.5/config -L${PREFIX}/pgsql/lib" \
	CPPFLAGS="-I`${PY_PREFIX}`/include/python1.5 -I${PREFIX}/pgsql/include" \
	${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.PyGreSQL

.include <bsd.port.mk>
