# Created by: Brent J. Nordquist <bjn@visi.com>
# $FreeBSD$

PORTNAME=	gdbm
PORTVERSION=	1.18.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	GNU

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GNU database manager

LICENSE=	GPLv3+

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool:keepla readline

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
		-e "s|BINOWN = bin|BINOWN = root|" \
		-e "s|BINGRP = bin|BINGRP = wheel|" \
		-e "s|libgdbm.la libgdbm_compat.la|& gdbm.info|" \
			${WRKSRC}/Makefile.in

.include <bsd.port.mk>
