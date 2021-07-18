# Created by: Martin Matuska <mm@FreeBSD.org>

PORTNAME=	fdk-aac
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
CATEGORIES=	audio

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Port of the Fraunhofer FDK AAC Codec Library

LICENSE=	FRAUNHOFER_FDK_AAC
LICENSE_NAME=	Software License for The Fraunhofer FDK AAC Codec Library for Android
LICENSE_FILE=	${WRKSRC}/NOTICE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

NOT_FOR_ARCHS=		sparc64
NOT_FOR_ARCHS_REASON=	not yet ported to this architecture

USES=		cmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	mstorsjo

PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.mk>
