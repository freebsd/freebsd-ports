# Created by: Brent J. Nordquist <bjn@visi.com>
# $FreeBSD$

PORTNAME=	gdbm
PORTVERSION=	1.9.1
CATEGORIES=	databases
MASTER_SITES=	GNU

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	The GNU database manager

OPTIONS_DEFINE=	COMPAT
COMPAT_DESC=	dbm/ndbm compatibility

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes

INFO=		gdbm
MAN3=		gdbm.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPAT}
CONFIGURE_ARGS+=--enable-libgdbm-compat
PLIST_SUB=	GDBM_COMPAT=""
.else
PLIST_SUB=	GDBM_COMPAT="@comment "
.endif

pre-everything::
.if ! ${PORT_OPTIONS:MCOMPAT}
	@${ECHO_MSG}
	@${ECHO_MSG} "If you need UNIX dbm/ndbm compatibility functions,"
	@${ECHO_MSG} "use \"make WITH=COMPAT\""
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|LIBS = @LIBS@ -lc|LIBS = @LIBS@|" \
			-e "s|BINOWN = bin|BINOWN = root|" -e "s|BINGRP = bin|BINGRP = wheel|" \
			-e "s|libgdbm.la libgdbm_compat.la|libgdbm.la libgdbm_compat.la gdbm.info|" \
			${WRKSRC}/Makefile.in

.include <bsd.port.mk>
