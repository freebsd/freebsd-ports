# $FreeBSD$

PORTNAME=	rainbow
DISTVERSION=	2.0.4
CATEGORIES=	biology
MASTER_SITES=	SF/bio-rainbow
DISTNAME=	rainbow_${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Efficient clustering and assembling of short reads, especially for RAD

LICENSE=	GPLv3+

USES=		gmake

PLIST_FILES=	bin/rainbow bin/ezmsim bin/rbasm

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} \
		${WRKSRC}/rainbow \
		${WRKSRC}/ezmsim \
		${WRKSRC}/rbasm \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
