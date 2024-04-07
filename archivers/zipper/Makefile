PORTNAME=	zipper
PORTVERSION=	1.5
PORTREVISION=	9
CATEGORIES=	archivers gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	Zipper-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for inspecting the contents of a compressed archive
WWW=		http://gap.nongnu.org/zipper/

USES=		gnustep
USE_GNUSTEP=	back build

post-patch:
	cd ${WRKSRC} && ${FIND} . -name "*#*" -exec ${RM} -v {} ";"

.include <bsd.port.mk>
