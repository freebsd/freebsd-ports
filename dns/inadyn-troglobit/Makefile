# Created by: Vladimir Vinogradenko <themylogin@gmail.com>
# $FreeBSD$

PORTNAME=		inadyn-troglobit
DISTVERSION=	2.2
CATEGORIES=		dns

MAINTAINER=	themylogin@gmail.com
COMMENT=	Dynamic DNS client with SSL/TLS support

LICENSE=	GPLv2

LIB_DEPENDS=libconfuse.so:devel/libconfuse \
			libgnutls.so:security/gnutls

PLIST_FILES=man/man8/inadyn.8.gz \
			man/man5/inadyn.conf.5.gz \
			share/doc/inadyn/COPYING \
			share/doc/inadyn/ChangeLog.md \
			share/doc/inadyn/README.md \
			sbin/inadyn

USES=		autoreconf libtool pkgconfig
USE_GITHUB=		yes
USE_RC_SUBR=	inadyn
GNU_CONFIGURE=	yes

GH_ACCOUNT=		troglobit
GH_PROJECT=		inadyn
GH_TAGNAME=		0e0001592fb77c6b68413da26a483d56edf12586

.include <bsd.port.mk>
