# ex:ts=8
# Ports collection makefile for:  boost
# Date Created:			  6 January 2002
# Whom:				  Paul Marquis <pmarquis@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	boost
PORTVERSION=	1.30.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	pmarquis@pobox.com
COMMENT=	Free peer-reviewed portable C++ source libraries

MAKE_ENV+=	BOOST_ROOT=${WRKSRC} BUILD="debug release"
MAKE_ENV+=	BOOST_BUILD_PATH="${WRKDIR}/gcc-custom" TOOLS="gcc-custom"
COMPILED_LIBS=	regex signals thread
.if defined(WITHOUT_PYTHON)
PLIST_SUB+=	BOOST_PYTHON="@comment "
.else
PLIST_SUB+=	BOOST_PYTHON=""
USE_PYTHON=	yes
MAKE_ENV+=	PYTHON="${PYTHON_CMD}" PYTHON_VERSION="${_PYTHON_VERSION}"
MAKE_ENV+=	PYTHON_INCLUDES="${PYTHON_INCLUDEDIR}"
MAKE_ENV+=	PYTHON_STDLIB_PATH="${PYTHON_LIBDIR}"
COMPILED_LIBS+=	python
.endif
INSTALLS_SHLIB=	yes
DOCFILES=	*.css *.gif *.htm *.html *.jpeg *.jpg *.png
BJAM=		${WRKSRC}/tools/build/jam_src/bin.freebsd/bjam

do-configure:
	${MKDIR} ${WRKDIR}/gcc-custom
	${SED} -E -e 's/%%GXX%%/${CXX}/g' -e 's/%%GCC%%/${CC}/g' < \
	    ${FILESDIR}/gcc-custom-tools.jam > \
	    ${WRKDIR}/gcc-custom/gcc-custom-tools.jam

do-build:
	cd ${WRKSRC}/tools/build/jam_src && ./build.sh gcc
.for lib in ${COMPILED_LIBS}
	cd ${WRKSRC}/libs/${lib}/build && ${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_FLAGS}
.endfor

do-install:
	${INSTALL_PROGRAM} ${BJAM} ${PREFIX}/bin/
	cd ${WRKSRC} && ${FIND} libs -type f -name \*.a -exec ${INSTALL_DATA} \{\} ${PREFIX}/lib \;
	cd ${WRKSRC} && ${FIND} libs -type f -name \*.so -exec ${INSTALL_PROGRAM} \{\} ${PREFIX}/lib \;
	cd ${WRKSRC} && ${FIND} boost -type d -exec ${MKDIR} ${PREFIX}/include/\{\} \;
	cd ${WRKSRC} && ${FIND} boost -type f -exec ${INSTALL_DATA} \{\} ${PREFIX}/include/\{\} \;
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${FIND} * -type f \( -name \*.htm ${DOCFILES:S/^/-o -name \\/} \) | ${TAR} cTf - - | ${TAR} xUCf ${DOCSDIR} -
	cd ${WRKSRC} && ${FIND} libs -type d -name example\* | ${TAR} cTf - - | ${TAR} xUCf ${EXAMPLESDIR} -
.endif

.include <bsd.port.mk>
