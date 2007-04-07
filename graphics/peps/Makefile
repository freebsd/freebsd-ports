# New ports collection makefile for:	peps
# Date created:				5 July 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	peps
PORTVERSION=	2.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.peps.redprince.net/unix/peps/ \
		http://www.peps.redprince.net/peps/2.0/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts EPS images to anti-aliased bitmaps

MAN1=		peps.1
PLIST_FILES=	bin/peps \
		etc/peps.mime \
		share/doc/${DISTNAME}/peps.pdf
PLIST_DIRS=	share/doc/${DISTNAME}

USE_GHOSTSCRIPT_RUN=	yes
MAKE_ENV=	DOCDIR=${PREFIX}/share/doc MAN1DIR=${MANPREFIX}/man/man1 \
		ETC=${PREFIX}/etc XBINDIR=${PREFIX}/bin

.if !defined(WITHOUT_X11)
PLIST_FILES+=	bin/xpeps
INSTALL_TARGET=	install xinstall
.endif

.include <bsd.port.mk>
