# ex:ts=8
# Ports collection makefile for:  boost
# Date Created:			  6 January 2002
# Whom:				  Paul Marquis <pmarquis@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	boost
PORTVERSION=	1.28.0
CATEGORIES=	devel
MASTER_SITES=	http://${PORTNAME}.sourceforge.net/release/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	pmarquis@pobox.com

MAKE_ENV=	BOOST_ROOT=${WRKSRC} TOOLS=gcc BUILD="debug release"
.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	yes
MAKE_ENV+=	PYTHON=${PYTHON_CMD} PYTHON_VERSION=${_PYTHON_VERSION} \
		PYTHON_INCLUDES="${PYTHON_INCLUDEDIR}" \
		PYTHON_STDLIB_PATH="${PYTHON_LIBDIR}"
.endif
INSTALLS_SHLIB=	yes

do-build:
	cd ${WRKSRC}/tools/build/jam_src; ${MAKE} ${MAKE_ARGS}
	cd ${WRKSRC}/libs/regex/build; ${MAKE_ENV} ${WRKSRC}/tools/build/jam_src/bin.freebsd/bjam
	cd ${WRKSRC}/libs/thread/build; ${MAKE_ENV} ${WRKSRC}/tools/build/jam_src/bin.freebsd/bjam
.if !defined(WITHOUT_PYTHON)
	cd ${WRKSRC}/libs/python/build; ${MAKE_ENV} ${WRKSRC}/tools/build/jam_src/bin.freebsd/bjam
.endif

do-install:
	cd ${WRKSRC}; ${FIND} libs -type f -name \*.a -exec ${INSTALL_DATA} \{\} ${PREFIX}/lib \;
	cd ${WRKSRC}; ${FIND} libs -type f -name \*.so -exec ${INSTALL_PROGRAM} \{\} ${PREFIX}/lib \;
	cd ${WRKSRC}; ${FIND} boost -type d -exec ${MKDIR} ${PREFIX}/include/\{\} \;
	cd ${WRKSRC}; ${FIND} boost -type f -exec ${INSTALL_DATA} \{\} ${PREFIX}/include/\{\} \;
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; ${FIND} . -name \*.htm -print | ${XARGS} -n 1 dirname | sort | uniq | ${SED} -e 's%^\.%${DOCSDIR}/%' | ${XARGS} ${MKDIR}
	cd ${WRKSRC}; ${FIND} . -name \*.htm -exec ${INSTALL_DATA} \{\} ${DOCSDIR}/\{\} \;
.endif

.include <bsd.port.mk>
