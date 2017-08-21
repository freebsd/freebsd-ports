# $FreeBSD$

PORTNAME=	ftp
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	ftp gnustep
MASTER_SITES=	SAVANNAH/gap
PKGNAMEPREFIX=	gnustep-
DISTNAME=	FTP-${PORTVERSION}

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Compact and handy FTP client for GNUstep

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build

post-patch:
	${REINPLACE_CMD} -e 's|^GNUSTEP_INSTALLATION_DIR|#GNUSTEP_INSTALLATION_DIR|' \
		${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
