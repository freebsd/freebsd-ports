# New ports collection makefile for:	py-gd
# Date created:		23 December 2001
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$

PORTNAME=	gd
PORTVERSION=	0.56
CATEGORIES=	graphics python
MASTER_SITES=	http://newcenturycomputers.net/projects/download.cgi/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gdmodule-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python interface to the GD library

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

.if defined(WITHOUT_X11)
USE_XPM=	yes
.endif
USE_REINPLACE=  yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
DISABLE_SIZE=	yes
PYSETUP=	Setup.py
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		-e 's,/usr/X11R6,${X11BASE},g' \
		-e 's,/usr/include/X11,${LOCALBASE}/include,g' \
		${WRKSRC}/${PYSETUP}
.if defined(WITHOUT_X11)
	${REINPLACE_CMD} -e 's/"X11", "Xpm",//' \
		-e 's/"ttf", "freetype",//' ${WRKSRC}/${PYSETUP}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/gddemo.py ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
