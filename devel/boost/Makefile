# ex:ts=8
# Ports collection makefile for:  boost
# Date Created:			  6 January 2002
# Whom:				  Paul Marquis <pmarquis@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	boost
PORTVERSION=	1.29.0
CATEGORIES=	devel
MASTER_SITES=	http://${PORTNAME}.sourceforge.net/release/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	pmarquis@pobox.com

MAKE_ENV=	BOOST_ROOT=${WRKSRC} TOOLS=gcc BUILD="debug release"
COMPILED_LIBS=	regex signals thread
.if defined(WITHOUT_PYTHON)
PLIST_SUB+=	BOOST_PYTHON="@comment "
.else
PLIST_SUB+=	BOOST_PYTHON=""
USE_PYTHON=	yes
MAKE_ENV+=	PYTHON=${PYTHON_CMD} PYTHON_VERSION=${_PYTHON_VERSION} \
		PYTHON_INCLUDES="${PYTHON_INCLUDEDIR}" \
		PYTHON_STDLIB_PATH="${PYTHON_LIBDIR}"
COMPILED_LIBS+=	python
.endif
INSTALLS_SHLIB=	yes
DOCFILES=	*.css *.gif *.htm *.html *.jpeg *.jpg *.png

do-build:
	cd ${WRKSRC}/tools/build/jam_src; ${MAKE} ${MAKE_ARGS}
.for lib in ${COMPILED_LIBS}
	cd ${WRKSRC}/libs/${lib}/build; ${MAKE_ENV} ${WRKSRC}/tools/build/jam_src/bin.freebsd/bjam
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/build/jam_src/bin.freebsd/bjam ${PREFIX}/bin/
	cd ${WRKSRC}; ${FIND} libs -type f -name \*.a -exec ${INSTALL_DATA} \{\} ${PREFIX}/lib \;
	cd ${WRKSRC}; ${FIND} libs -type f -name \*.so -exec ${INSTALL_PROGRAM} \{\} ${PREFIX}/lib \;
	cd ${WRKSRC}; ${FIND} boost -type d -exec ${MKDIR} ${PREFIX}/include/\{\} \;
	cd ${WRKSRC}; ${FIND} boost -type f -exec ${INSTALL_DATA} \{\} ${PREFIX}/include/\{\} \;
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}; ${FIND} * -type f \( -name \*.htm ${DOCFILES:S/^/-o -name \\/} \) | ${TAR} cTf - - | ${TAR} xUCf ${DOCSDIR} -
	cd ${WRKSRC}; ${FIND} libs -type d -name example\* | ${TAR} cTf - - | ${TAR} xUCf ${EXAMPLESDIR} -
.endif

.include <bsd.port.mk>
