PORTNAME=	libdrizzle
PORTVERSION=	1.0
CATEGORIES=	databases
MASTER_SITES=	https://launchpadlibrarian.net/74651825/
DISTNAME=	drizzle7-2011.07.21
PORTSCOUT=	limit:^1\.

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Client and protocol library for the Drizzle database
WWW=		https://launchpad.net/drizzle

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
USES=		gmake libtool ssl
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--without-server \
		--disable-boost \
		--disable-dtrace \
		--disable-libcurl \
		--disable-libldap \
		--disable-libsqlite3 \
		--disable-nls
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

ALL_TARGET=	libdrizzle-1.0
INSTALL_TARGET=	install-libdrizzle-1.0
MAKE_ARGS=	LIBS=-lcrypto \
		INSTALL_STRIP_FLAG=-s \
		oldlibdrizzlepkgconfigdir=${PREFIX}/libdata/pkgconfig

CONFLICTS_INSTALL=	libdrizzle-redux # lib/libdrizzle.so

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=--disable-64bit
.endif

post-configure:
	@${TOUCH} ${WRKSRC}/.plugin.scan \
		${WRKSRC}/config/pandora-plugin.list \
		${WRKSRC}/config/pandora-plugin.am

.include <bsd.port.mk>
