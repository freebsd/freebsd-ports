# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	gd
PORTVERSION=	0.58
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gdmodule-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to the GD library

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYSETUP=	Setup.py
USE_PYTHON_PREFIX=	yes
PYDISTUTILS_PKGNAME=	gdmodule

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		'/\/usr\/lib/d ; \
		 /\/usr\/include/d ; \
		 /\/usr\/X11R6/d ; \
		 s|/opt/gnome|${LOCALBASE}| ; \
		 /"jpeg", "png", "gif", "z",/d ; \
		 /"X11", "Xpm",/d ; \
		 /"ttf", "freetype",/d' \
		${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
