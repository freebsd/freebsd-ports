# $FreeBSD$

PORTNAME=	libpillowfight
DISTVERSION=	0.2.4
CATEGORIES=	graphics python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library containing various image processing algorithms

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gmake:devel/gmake

USES=		cmake:outsource
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org/World
GL_ACCOUNT=	OpenPaperwork
GL_COMMIT=	3a7ebba75f4c060ac1707900bd8891e8d200b1c6
USE_LDCONFIG=	yes

PLIST_FILES=	include/pillowfight/pillowfight.h \
		include/pillowfight/util.h \
		lib/libpillowfight.so

pre-configure:
	@cd ${WRKSRC} && ${GMAKE} version

.include <bsd.port.mk>
