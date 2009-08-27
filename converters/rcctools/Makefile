# New ports collection makefile for:	rcctools
# Date created:			20-08-2009
# Whom:				Alex Keda <admin@lissyara.su>
#
# $FreeBSD$
#

PORTNAME=	rcctools
PORTVERSION=	0.1.1
CATEGORIES=	converters
MASTER_SITES=	SF/rusxmms/${PORTNAME}/${PORTVERSION}

MAINTAINER=	admin@lissyara.su
COMMENT=	Charset conversion utility with language and encoding autodetection

LIB_DEPENDS=	rcc.2:${PORTSDIR}/devel/librcc

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/rcc-recode

.include <bsd.port.mk>
