# Created by: Brent J. Nordquist <bjn@visi.com>
# $FreeBSD$

PORTNAME=	gdbm
PORTVERSION=	1.11
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU database manager

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool:keepla

MAKE_JOBS_UNSAFE=	yes

INFO=		gdbm

OPTIONS_DEFINE=	COMPAT NLS
OPTIONS_SUB=	yes
COMPAT_DESC=	Enable dbm/ndbm compatibility
COMPAT_CONFIGURE_ENABLE=	libgdbm-compat
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e "s|LIBS = @LIBS@ -lc|LIBS = @LIBS@|" \
		-e "s|BINOWN = bin|BINOWN = root|" -e "s|BINGRP = bin|BINGRP = wheel|" \
		-e "s|libgdbm.la libgdbm_compat.la|libgdbm.la libgdbm_compat.la gdbm.info|" \
			${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgdbm*.so

.include <bsd.port.mk>
