# Created by: Kuang-che Wu <kcwu@csie.org>
# $FreeBSD$

PORTNAME=	libchewing
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	chinese textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chewing intelligent phonetic input method library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/makeinfo:print/texinfo

USES=		cmake libtool pathfix pkgconfig sqlite tar:bzip2
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	chewing

CMAKE_ARGS+=	-DMAKEINFO=${LOCALBASE}/bin/makeinfo
CFLAGS+=	-I${LOCALBASE}/include
INFO=		libchewing

.include <bsd.port.mk>
