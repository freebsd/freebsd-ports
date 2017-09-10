# Created by: Hannes Hauswedell <h2+fbsdports@fsfe.org>
# $FreeBSD$

PORTNAME=	seqan-apps
PORTVERSION=	2.2.0
DISTVERSIONPREFIX=	seqan-v
PORTREVISION=	6
CATEGORIES=	biology

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Official Bioinformatic applications based on the SeqAn library

LICENSE=	BSD3CLAUSE LGPL3 GPLv3
LICENSE_COMB=	multi

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	seqan
GH_PROJECT=	seqan

# once #199603 is resolved, do the following instead of USE_GCC
# USES=		cmake:outsource compiler:openmp,c++14-lang
USES=		cmake:outsource
CMAKE_ARGS=	-DSEQAN_BUILD_SYSTEM="SEQAN_RELEASE_APPS"

USE_GCC=	yes

BROKEN_aarch64=		fails to compile: Error: unknown mnemonic rep -- rep
BROKEN_powerpc64=	fails to compile: Error: unrecognized opcode: rep

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
PLIST_SUB+=	RM_I386="@comment "
.else
PLIST_SUB+=	RM_I386=""
.endif

.include <bsd.port.post.mk>
