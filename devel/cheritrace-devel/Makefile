# Created by: David Chisnall <theraven@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cheritrace
PORTVERSION=	0.0.1
PORTREVISION=	2
CATEGORIES=	devel security

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Library and tool for interacting with CHERI streamtraces

BROKEN=		fails to build: cheritrace-0.0.1_2 depends on shared library: libLLVMCore.so - not found
DEPRECATED=	Broken for more than 5 months
EXPIRATION_DATE=	2018-08-20
BROKEN_powerpc64=	fails to compile: addressmap.cc: 'stoll' is not a member of 'std'

BUILD_DEPENDS=	llvm-config-cheri:devel/llvm-cheri
LIB_DEPENDS=	libLLVMCore.so:devel/llvm-cheri

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-CHERI
GH_TAGNAME=	a7ddf11

CMAKE_ARGS=	-DLLVM_CONFIG=${LOCALBASE}/bin/llvm-config-cheri

.include <bsd.port.mk>
