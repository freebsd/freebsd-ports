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
PORTVERSION=	0.9b-20020814
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://dickey.his.com/dialog/
DISTNAME=	${PORTNAME:S|^c||}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	alane@freebsd.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	makefile

MAN1=		cdialog.1

BINDIR=		${PREFIX}/bin
MAN1DIR=	${MANPREFIX}/man/man1

do-install:
	cd ${WRKSRC};\
	${INSTALL_PROGRAM} dialog ${BINDIR}/cdialog;\
	${INSTALL_DATA} dialog.1 ${MAN1DIR}/cdialog.1

.include <bsd.port.mk>
#EOF
