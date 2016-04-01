# Created by: Alex Keda <admin@lissyara.su>
# $FreeBSD$

PORTNAME=	rcctools
PORTVERSION=	0.1.1
PORTREVISION=	4
CATEGORIES=	converters
MASTER_SITES=	SF/rusxmms/${PORTNAME}/${PORTVERSION}

MAINTAINER=	admin@lissyara.su
COMMENT=	Charset conversion utility with language and encoding autodetection

LIB_DEPENDS=	librcc.so:devel/librcc

USES=		tar:bzip2
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PLIST_FILES=	bin/rcc-recode

.include <bsd.port.mk>
