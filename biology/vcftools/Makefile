# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	vcftools
PORTVERSION=	0.1.14
DISTVERSIONPREFIX=	v
CATEGORIES=	biology
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Tools for working with VCF genomics files

LICENSE=	LGPL3

USES=		autoreconf gmake perl5 pkgconfig

GNU_CONFIGURE=	yes
# No zlib.pc on 9.x
CONFIGURE_ENV=	ZLIB_CFLAGS=" " ZLIB_LIBS="-lz"

USE_GITHUB=	yes

.include <bsd.port.mk>
