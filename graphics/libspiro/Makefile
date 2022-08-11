PORTNAME=	libspiro
DISTVERSION=	20200505
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/fontforge/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}-dist-${DISTVERSION}

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Library to convert clothoid splines into Bezier splines

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool pathfix

CPE_VENDOR=	libspiro_project
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
