PORTNAME=	zipper
DISTVERSION=	1.5
PORTREVISION=	9
CATEGORIES=	archivers gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	Zipper-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for inspecting the contents of a compressed archive
WWW=		https://gap.nongnu.org/zipper/

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build

post-patch:
	cd ${WRKSRC} && ${FIND} . -name "*#*" -delete -print

.include <bsd.port.mk>
