# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	ncdialog
# Date created:		2002-12-15
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	dialog
PORTVERSION=	0.9b-20020814
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	ftp://dickey.his.com/dialog/
PKGNAMEPREFIX=	ncurses-
EXTRACT_SUFX=	.tgz

MAINTAINER=	alane@freebsd.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	makefile

MAN1=		dialog.1
MANLINKS=	dialog.1 ncdialog.1

post-install:
	cd ${PREFIX}/bin; ${RM} -fv ncdialog; ${LN} -fv dialog ncdialog
	cd ${MANPREFIX}/man/man1; \
		${RM} -fv ncdialog.1; ${LN} -fv dialog.1 ncdialog.1

.include <bsd.port.mk>
#EOF
