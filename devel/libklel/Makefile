# $FreeBSD$

PORTNAME=	libklel
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	klm@uidzero.org
COMMENT=	KoreLogic Expression Language library

LIB_DEPENDS=	libpcre.so:devel/pcre

GNU_CONFIGURE=	yes
USES=		perl5 libtool
USE_PERL5=	build
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--with-pcre=${LOCALBASE}

.include <bsd.port.mk>
