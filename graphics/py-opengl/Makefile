# New ports collection makefile for:	PyOpenGL
# Version required:	1.5.5
# Date created:		Wed Aug 18 18:49:17 EDT 1999
# Whom:			Randall Hopper <aa8vb@ipass.net>
#
# $FreeBSD$
#

DISTNAME=	PyOpenGL-1.5.5
PKGNAME=	py-opengl-1.5.5
CATEGORIES=	graphics python
MASTER_SITES=	http://starship.python.net/crew/da/

MAINTAINER=	aa8vb@ipass.net

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python \
		${NUMPYDIR}/Numeric.py:${PORTSDIR}/math/numpy
RUN_DEPENDS=	python:${PORTSDIR}/lang/python \
		${NUMPYDIR}/Numeric.py:${PORTSDIR}/math/numpy
LIB_DEPENDS=	GL.14:${PORTSDIR}/graphics/Mesa3

ALL_TARGET=	default

WRKSRC=		${WRKDIR}/${DISTNAME}/src

OSMAJOR!=	/usr/bin/uname -r | sed -e 's/\..*//'
PLIST_SUB+=	OSMAJOR=${OSMAJOR}

#
# Support for Numeric is compiled in by default.
#
WITH_NUMERIC?=	yes
NUMPYDIR=	${LOCALBASE}/lib/python1.5/site-packages/numerical

#
# The standard setup file
#
SETUP_FILES=	${FILESDIR}/Setup.base

#
# Support for Togl is compiled in by default.
#
WITH_TOGL?=	yes
.if defined(WITH_TOGL) && $(WITH_TOGL) == yes
SETUP_FILES+=	${FILESDIR}/Setup.add.togl
LIB_DEPENDS+=	tk82.1:${PORTSDIR}/x11-toolkits/tk82
.endif

.include <bsd.port.pre.mk>

do-configure:
	${CAT} ${SETUP_FILES} \
	  | ${SED} -e 's|X11BASE|${X11BASE}|g' \
	        -e 's|LOCALBASE|${LOCALBASE}|g' \
	  > ${WRKSRC}/Setup.proto

do-build:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} python BUILD.py)

pre-install:
	@# Remove togl.so so we don't install it; that's the Togl pkg's job
	${RM} -f ${WRKSRC}/togl.so
	find ${WRKDIR} -name '*.so*' | xargs strip

do-install:
	@(cd ${WRKSRC} && ${CONFIGURE_ENV} python INSTALL.py)

.include <bsd.port.post.mk>
