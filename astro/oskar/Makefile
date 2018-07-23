# $FreeBSD$

PORTNAME=	OSKAR
DISTVERSION=	2.7.0
CATEGORIES=	astro

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SKA Radio telescope simulator

LICENSE=	GPLv2
xLICENSE_FILES=	${WRKSRC}/../COPYING

LIB_DEPENDS=	libcfitsio.so:astro/cfitsio

USES=		cmake:outsource localbase:ldflags python qt:5 shebangfix
SHEBANG_FILES=	apps/oskar_convert_cst_to_scalar.py
USE_GITHUB=	yes
GH_ACCOUNT=	OxfordSKA
USE_QT=		core gui network widgets buildtools_build qmake_build
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DFREEBSD_FILESDIR:STRING=${FILESDIR}

.include <bsd.port.mk>
