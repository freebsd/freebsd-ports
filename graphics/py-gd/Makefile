# New ports collection makefile for:	py-gd
# Date created:		23 December 2001
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$

PORTNAME=	gd
PORTVERSION=	0.26
CATEGORIES=	graphics python
MASTER_SITES=	http://newcenturycomputers.net/projects/download.cgi/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gdmodule-${PORTVERSION}

MAINTAINER=	perky@fallin.lv

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd \
		ttf.4:${PORTSDIR}/print/freetype

USE_PYTHON=	yes
EXCMD=		/usr/bin/ex
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,^${LOCALBASE}/,,g} \
		EXAMPLE_DIR=${EXAMPLE_DIR:S,^${PREFIX}/,,g}
EXAMPLE_DIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

.if !defined(WITHOUT_X11)
USE_XPM=	yes
.endif

post-patch:
	${EXCMD} -c 's,^\(gd.*\)$$,\1 -I${PREFIX}/include/gd,g|wq!' ${WRKSRC}/Setup
.if defined(WITHOUT_X11)
	${EXCMD} -c 's,-lX11 -lXpm,,g|wq!' ${WRKSRC}/Setup
.endif

pre-build:
	cd ${WRKSRC} && ${MAKE} -f Makefile.pre.in boot

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLE_DIR}
	${INSTALL_DATA} ${WRKSRC}/gddemo.py ${EXAMPLE_DIR}
.endif

.include <bsd.port.mk>
