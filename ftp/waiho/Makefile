# $FreeBSD$

PORTNAME=	waiho
PORTVERSION=	0.2
PORTREVISION=	5
CATEGORIES=	ftp gnustep
MASTER_SITES=	http://www.roard.com/waiho/download/
DISTNAME=	Waiho-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple FTP client for GNUstep

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/Waiho.app/Waiho

.include <bsd.port.mk>
