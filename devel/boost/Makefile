# ex:ts=8
# Ports collection makefile for:  boost
# Date Created:			  6 January 2002
# Whom:				  Paul Marquis <pmarquis@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	boost
PORTVERSION=	1.26.0
CATEGORIES=	devel
MASTER_SITES=	http://${PORTNAME}.sourceforge.net/release/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	pmarquis@pobox.com

USE_PYTHON=	yes
MAKE_ENV=	BOOST_ROOT=${WRKSRC} TOOLS=gcc BUILD=debug \
		PYTHON=${PYTHON_CMD} PYTHON_VERSION=${PYTHON_VERSION} \
		PYTHON_INCLUDES="<include>${PYTHON_INCLUDEDIR}"
INSTALLS_SHLIB=	yes

do-build:
	cd ${WRKSRC}/tools/build/jam_src; ${MAKE} ${MAKE_ARGS}
	cd ${WRKSRC}; ${MAKE_ENV} tools/build/jam_src/bin.freebsd/jam -d2

do-install:
	cd ${WRKSRC}; ${FIND} libs -type f -name \*.a -exec ${INSTALL_DATA} \{\} ${PREFIX}/lib \;
	cd ${WRKSRC}; ${FIND} libs -type f -name \*.so -exec ${INSTALL_PROGRAM} \{\} ${PREFIX}/lib \;
	cd ${WRKSRC}; ${FIND} boost -type d -exec ${MKDIR} ${PREFIX}/include/\{\} \;
	cd ${WRKSRC}; ${FIND} boost -type f -exec ${INSTALL_DATA} \{\} ${PREFIX}/include/\{\} \;

.if !defined(NOPORTDOCS)
post-install:
	cd ${WRKSRC}; ${FIND} . -name \*.htm -print | ${XARGS} -n 1 dirname | sort | uniq | ${SED} -e 's%^\.%${DOCSDIR}/%' | ${XARGS} ${MKDIR}
	cd ${WRKSRC}; ${FIND} . -name \*.htm -exec ${INSTALL_DATA} \{\} ${DOCSDIR}/\{\} \;
.endif

.include <bsd.port.mk>
