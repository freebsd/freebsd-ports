# Created by: Brent J. Nordquist <bjn@visi.com>
# $FreeBSD$

PORTNAME=	gdbm
PORTVERSION=	1.11
CATEGORIES=	databases
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU database manager

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USES=		gmake

MAKE_JOBS_UNSAFE=	yes

INFO=		gdbm

OPTIONS_DEFINE=	COMPAT NLS
COMPAT_DESC=	Enable dbm/ndbm compatibility

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPAT}
CONFIGURE_ARGS=	--enable-libgdbm-compat
PLIST_SUB+=	GDBM_COMPAT=""
.else
PLIST_SUB+=	GDBM_COMPAT="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|LIBS = @LIBS@ -lc|LIBS = @LIBS@|" \
		-e "s|BINOWN = bin|BINOWN = root|" -e "s|BINGRP = bin|BINGRP = wheel|" \
		-e "s|libgdbm.la libgdbm_compat.la|libgdbm.la libgdbm_compat.la gdbm.info|" \
			${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgdbm.so.4
.if ${PORT_OPTIONS:MCOMPAT}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgdbm_compat.so.4
.endif

.include <bsd.port.mk>
