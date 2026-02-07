PORTNAME=	libmad
PORTVERSION=	0.16.4
CATEGORIES=	audio
MASTER_SITES=	https://codeberg.org/tenacityteam/libmad/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MPEG audio decoder library
WWW=		https://www.underbit.com/products/mad/ \
		https://codeberg.org/tenacityteam/libmad

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake cpe

CMAKE_OFF=	MADD_ASM MADD16_ASM
CMAKE_ON=	BUILD_SHARED_LIBS ${CMAKE_ON_${ARCH}}
CMAKE_ON_armv6=	ASO
CMAKE_ON_armv7=	ASO
CMAKE_ON_i386=	ASO

USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/libmad

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CPE_VENDOR=	underbit

OPTIONS_SINGLE=	OPTIMIZE
OPTIONS_SINGLE_OPTIMIZE=ACCURACY SPEED
OPTIONS_DEFAULT=SPEED
ACCURACY_DESC=	Optimize for accuracy over speed
SPEED_DESC=	Optimize for speed over accuracy

ACCURACY_CMAKE_ON=	-DOPTIMIZE=ACCURACY
SPEED_CMAKE_ON=		-DOPTIMIZE=SPEED

.include <bsd.port.mk>
