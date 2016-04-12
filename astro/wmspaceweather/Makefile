# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmspaceweather
PORTVERSION=	1.04
PORTREVISION=	5
CATEGORIES=	astro windowmaker
MASTER_SITES=	https://api.opensuse.org/public/source/openSUSE:Factory/WindowMaker-applets/ \
		ftp://ftp.canadatux.org/linux/windowmaker/
DISTNAME=	wmSpaceWeather-${PORTVERSION}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	DockApp that shows the weather at geosynchronous orbit

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Time-modules>=0:devel/p5-Time-modules

WRKSRC=		${WRKDIR}/${DISTNAME}/wmSpaceWeather

USES=		shebangfix
SHEBANG_FILES=	GetKp
USE_XORG=	x11 xext xpm
ALL_TARGET=	clean all
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/GetKp bin/wmSpaceWeather \
		man/man1/wmSpaceWeather.1.gz

.include <bsd.port.mk>
