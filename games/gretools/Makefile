# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gretools
PORTVERSION=	1.2.4
PORTREVISION=	12
CATEGORIES=	games gnome
MASTER_SITES=	http://randomwalker.info/gretools/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME vocabulary builder

LICENSE=	GPLv2

USE_GNOME=	gnomehack gnomeprefix pygnome2
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PKGCONFIG=	build
INSTALLS_OMF=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/python -t|/usr/bin/env python|g ; \
		 s|@prefix@|${LOCALBASE}|g ; s|@share@|share|g' \
		 ${WRKSRC}/gretools.in
	@${REINPLACE_CMD} -e 's|gtk\.TRUE|True|g ; \
		 s|gtk\.FALSE|False|g ; \
		 s|gtk\.idle_add|gobject\.idle_add|g' ${WRKSRC}/gretools.py

.include <bsd.port.mk>
