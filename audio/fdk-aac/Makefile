# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fdk-aac
PORTVERSION=	0.1.6
CATEGORIES=	audio
MASTER_SITES=	SF/opencore-amr/${PORTNAME}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Port of the Fraunhofer FDK AAC Codec Library

LICENSE=	FRAUNHOFER_FDK_AAC
LICENSE_NAME=	Software License for The Fraunhofer FDK AAC Codec Library for Android
LICENSE_FILE=	${WRKSRC}/NOTICE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

NOT_FOR_ARCHS=		sparc64
NOT_FOR_ARCHS_REASON=	not yet ported to this architecture

LIBS+=		-lm
GNU_CONFIGURE=	yes
USES=		libtool pathfix
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
