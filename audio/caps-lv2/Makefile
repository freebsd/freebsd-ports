# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	caps-lv2
PORTVERSION=	g20170626
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 version of the C* Audio Plugin Suite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		gmake localbase
USE_GITHUB=	yes
GH_ACCOUNT=	moddevices
GH_TAGNAME=	072e2fe

# It suffers from the regression in clang-6: https://bugs.llvm.org/show_bug.cgi?id=36916
LLVM_VER=	50
BUILD_DEPENDS+=	clang${LLVM_VER}:devel/llvm${LLVM_VER}
CPP=		clang-cpp${LLVM_VER}
CC=		clang${LLVM_VER}
CXX=		clang++${LLVM_VER}

post-patch:
	@${REINPLACE_CMD} -e "s|__APPLE__|__FreeBSD__|" \
		${WRKSRC}/dsp/v4f_IIR2.h

.include <bsd.port.mk>
