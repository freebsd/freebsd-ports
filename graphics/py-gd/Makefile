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

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd

USE_PYTHON=	yes
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,^${LOCALBASE}/,,g} \
		EXAMPLE_DIR=${EXAMPLE_DIR:S,^${PREFIX}/,,g}
EXAMPLE_DIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

.if !defined(WITHOUT_X11)
USE_XPM=	yes
.endif

post-patch:
	${PERL} -pi -e 's,^(gd.*)$$,\1 -I${LOCALBASE}/include/gd -L${LOCALBASE}/lib,g; s,-lttf,,g; s,/usr/X11R6,${X11BASE},g;' \
		${WRKSRC}/Setup
.if defined(WITHOUT_X11)
	${PERL} -pi -e 's,-lX11 -lXpm,,g' ${WRKSRC}/Setup
.endif

pre-build:
	cd ${WRKSRC} && ${MAKE} -f Makefile.pre.in boot

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLE_DIR}
	${INSTALL_DATA} ${WRKSRC}/gddemo.py ${EXAMPLE_DIR}
.endif

.include <bsd.port.mk>
