PORTNAME=	openfec
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.2.12
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Forward Error Correction Library
WWW=		https://github.com/roc-streaming/openfec

# BSD2CLAUSE for the inlined FEC code by Luigi Rizzo
# LDPC license for the inlined code from Radford Neal's LDPC project
# which is similar to MIT license
LICENSE=	BSD2CLAUSE CeCCIL CeCCIL-C LDPC
LICENSE_COMB=	multi
LICENSE_NAME_CeCCIL=	CEA CNRS INRIA Logiciel Libre License
LICENSE_FILE_CeCCIL=	${WRKSRC}/Licence_CeCILL_V2-en.txt
LICENSE_PERMS_CeCCIL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_NAME_CeCCIL-C=	CEA CNRS INRIA Logiciel Libre Component License
LICENSE_FILE_CeCCIL-C=	${WRKSRC}/LICENCE_CeCILL-C_V1-en.txt
LICENSE_PERMS_CeCCIL-C=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_NAME_LDPC=	Radford Neal's LDPC simulator licence
LICENSE_FILE_LDPC=	${FILESDIR}/COPYRIGHT-LDPC
LICENSE_PERMS_LDPC=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake pathfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	roc-streaming

.if defined(WITH_DEBUG)
CFLAGS+=	-DOF_DEBUG
.endif

TEST_TARGET=	test

.include <bsd.port.mk>
