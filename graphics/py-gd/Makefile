# New ports collection makefile for:	py-gd
# Date created:		23 December 2001
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$

PORTNAME=	gd
PORTVERSION=	0.40
CATEGORIES=	graphics python
MASTER_SITES=	http://newcenturycomputers.net/projects/download.cgi/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gdmodule-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd

USE_XPM=	yes
USE_REINPLACE=  yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
PYSETUP=	Setup.py
EXAMPLE_DIR=	${PREFIX}/share/examples/py-gd

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		-e 's,/usr/X11R6,${X11BASE},g' \
		-e 's,/usr/include/X11,${LOCALBASE}/include/gd,g' \
		${WRKSRC}/${PYSETUP}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLE_DIR}
	${INSTALL_DATA} ${WRKSRC}/gddemo.py ${EXAMPLE_DIR}
.endif

.include <bsd.port.mk>
