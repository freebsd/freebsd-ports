# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fdk-aac
DISTVERSIONPREFIX=	v
DISTVERSION=	v2.0.1-568
DISTVERSIONSUFFIX=	-g77ee4dd
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
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	mstorsjo
GH_TAGNAME=	77ee4dd

.include <bsd.port.mk>
