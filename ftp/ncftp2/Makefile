# New ports collection makefile for:    ncftp2
# Date created:         4 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	ncftp
PORTVERSION=	2.4.3
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.ncftp.com/ncftp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FTP replacement with advanced user interface

.if defined(INSTALL_AS_NCFTP)
LATEST_LINK=	ncftp
.else
LATEST_LINK=	ncftp2
.endif
PLIST_FILES=	bin/${LATEST_LINK}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_func_getmaxyx=yes ac_cv_lib_readline=yes
MAN1=		ncftp2.1

.if defined(WITH_SOCKS)
BUILD_DEPENDS=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=--enable-socks5
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "Use INSTALL_AS_NCFTP=yes to install ncftp1 as ${PREFIX}/bin/ncftp"
	@${ECHO} ""

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/ncftp $(PREFIX)/bin/${LATEST_LINK}
	$(INSTALL_MAN) $(WRKSRC)/ncftp.1 $(PREFIX)/man/man1/ncftp2.1

.include <bsd.port.mk>
