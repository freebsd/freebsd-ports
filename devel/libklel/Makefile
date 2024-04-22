PORTNAME=	libklel
PORTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	klm@uidzero.org
COMMENT=	KoreLogic Expression Language library
WWW=		https://sourceforge.net/projects/libklel/

LIB_DEPENDS=	libpcre.so:devel/pcre

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		perl5 libtool
USE_PERL5=	build
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--with-pcre=${LOCALBASE}

.include <bsd.port.mk>
