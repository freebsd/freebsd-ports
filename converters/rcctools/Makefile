# Created by: Alex Keda <admin@lissyara.su>
# $FreeBSD$

PORTNAME=	rcctools
PORTVERSION=	0.1.1
PORTREVISION=	3
CATEGORIES=	converters
MASTER_SITES=	SF/rusxmms/${PORTNAME}/${PORTVERSION}

MAINTAINER=	admin@lissyara.su
COMMENT=	Charset conversion utility with language and encoding autodetection

LIB_DEPENDS=	librcc.so:${PORTSDIR}/devel/librcc

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/rcc-recode

.include <bsd.port.mk>
