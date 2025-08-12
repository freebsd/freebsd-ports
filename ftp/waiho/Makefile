PORTNAME=	waiho
PORTVERSION=	0.2
PORTREVISION=	13
CATEGORIES=	ftp gnustep
MASTER_SITES=	http://www.roard.com/waiho/download/
DISTNAME=	Waiho-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple FTP client for GNUstep
WWW=		http://www.roard.com/waiho/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz gnustep
USE_GNUSTEP=	back build

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Waiho.app/Waiho

.include <bsd.port.mk>
