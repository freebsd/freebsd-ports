# Created by: Vladimir Vinogradenko <themylogin@gmail.com>
# $FreeBSD$

PORTNAME=		inadyn-troglobit
DISTVERSION=	0.0.0
CATEGORIES=		dns

USE_GITHUB=		yes
GH_ACCOUNT=		troglobit
GH_PROJECT=		inadyn
GH_TAGNAME=		0e0001592fb77c6b68413da26a483d56edf12586

MAINTAINER=	themylogin@gmail.com
COMMENT=	Dynamic DNS client with SSL/TLS support

LICENSE=	GPLv2

LIB_DEPENDS=libconfuse.so:devel/libconfuse \
            libgnutls.so:security/gnutls

USES=		autoreconf libtool pkgconfig
USE_RC_SUBR=	inadyn
GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.include <bsd.port.mk>
