PORTNAME=	libspiro
DISTVERSION=	20221101
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/fontforge/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}-dist-${DISTVERSION}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Library to convert clothoid splines into Bezier splines
WWW=		https://github.com/fontforge/libspiro

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool pathfix
CPE_VENDOR=	libspiro_project
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

.include <bsd.port.mk>
