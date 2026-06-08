PORTNAME=	faad2
DISTVERSION=	2.11.2
PORTEPOCH=	1
CATEGORIES=	audio

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG-2 and MPEG-4 AAC audio decoder
WWW=		https://github.com/knik0/faad2

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake cpe
CPE_VENDOR=	faad2_project
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	knik0

PLIST_SUB=	SOVERSION=${DISTVERSION}

.include <bsd.port.mk>
