# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cld
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	chromium-compact-language-detector
DISTNAME=	compact-language-detector-${PORTVERSION}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Chromium compact language detector library

BROKEN=		Unfetchable (google code has gone away)

USES=		libtool pathfix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

ONLY_FOR_ARCHS=	i386 amd64 armv6 powerpc
ONLY_FOR_ARCHS_REASON=	hardcoded set of supported archs

.include <bsd.port.mk>
