# Created by: sobomax
# $FreeBSD$

PORTNAME=	bcg729
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://linphone.org/releases/sources/bcg729/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Software G729A encoder and decoder library written in C

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_STATIC=NO

.include <bsd.port.mk>
