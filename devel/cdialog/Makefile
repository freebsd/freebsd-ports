# ex:ts=8
# -*-mode: makefile-*-
#
# New ports collection makefile for:	ncdialog
# Date created:		2003-01-11
# Whom:			AlanE <alane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	cdialog
PORTVERSION=	0.9b.20030308
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/dialog/
DISTNAME=	${PORTNAME:S|^c||}-${PORTVERSION:S|.200|-200|}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An enhanced version of 'dialog' to work with ncurses

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	makefile

BINDIR?=	${PREFIX}/bin
INCLUDEDIR?=	${PREFIX}/include/cdialog
LIBDIR?=	${PREFIX}/lib
MAN1DIR?=	${MANPREFIX}/man/man1

do-install:
	cd ${WRKSRC};\
	${MKDIR} ${BINDIR} ${INCLUDEDIR} ${LIBDIR}; \
	${INSTALL_PROGRAM} dialog ${BINDIR}/cdialog;\
	${INSTALL_DATA} dialog.h colors.h ${INCLUDEDIR}; \
	$(INSTALL_DATA) libdialog.a $(LIBDIR)/libcdialog.a;\
	${INSTALL_DATA} dialog.1 ${MAN1DIR}/cdialog.1

.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages.mk"
.include <bsd.port.post.mk>
