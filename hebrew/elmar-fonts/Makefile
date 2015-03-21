# Created by: nadav@cs.technion.ac.il
# $FreeBSD$

PORTNAME=	elmar-fonts
PORTVERSION=	3.3
PORTREVISION=	4
CATEGORIES=	hebrew x11-fonts
DISTNAME=	H.fonts
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	cpm@fbsd.es
COMMENT=	Collection of Hebrew fonts from El-Mar software Ltd

USES=		fonts
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
FONTNAME=	hebrew

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${TAR} -C ${STAGEDIR}${FONTSDIR} -xZpf \
		${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.mk>
