# ex:ts=8
# Ports collection makefile for:  boost
# Date Created:			  6 January 2002
# Whom:				  Paul Marquis <pmarquis@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	boost
PORTVERSION=	1.30.2
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	pmarquis@pobox.com
COMMENT=	Free peer-reviewed portable C++ source libraries

MAKE_ENV=	BOOST_ROOT=${WRKSRC} BUILD="debug release"

.if defined(WITH_PYTHON)
USE_PYTHON=	yes
# 1.30.2 doesn't support python2.3
PYTHON_VERSION=	python2.2
COMPILED_LIBS=	python
PLIST_SUB=	BOOST_PYTHON=""
MAKE_ENV+=	PYTHON_ROOT="${PREFIX}" \
		PYTHON_VERSION="${_PYTHON_VERSION}" \
		PYTHON_INCLUDES="${PYTHON_INCLUDEDIR}" \
		PYTHON_LIB_PATH="${PYTHON_LIBDIR}" 
.else
PLIST_SUB=	BOOST_PYTHON="@comment "
.endif

INSTALLS_SHLIB=	yes
DOCFILES=	*.css *.gif *.htm *.html *.jpeg *.jpg *.png

BJAM=		${WRKSRC}/tools/build/jam_src/bin.freebsd/bjam
  
COMPILED_LIBS+=	date_time filesystem regex signals test thread

.include <bsd.port.pre.mk>

do-configure:
# for -pthread options
.if ${OSVERSION} >= 500016
	cd ${WRKSRC} && patch < ${FILESDIR}/gcc-tools.jam.diff
.endif

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

.include <bsd.port.post.mk>
