# New ports collection makefile for:    ncftp2
# Date created:         4 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	ncftp
PORTVERSION=	2.4.3
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FTP replacement with advanced user interface

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_func_getmaxyx=yes ac_cv_lib_readline=yes
MAN1=		ncftp2.1
PLIST_FILES=	bin/ncftp2

.if defined(WITH_SOCKS)
BUILD_DEPENDS=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=   --enable-socks5
.endif

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/ncftp $(PREFIX)/bin/ncftp2
	$(INSTALL_MAN) $(WRKSRC)/ncftp.1 $(PREFIX)/man/man1/ncftp2.1

.include <bsd.port.mk>
