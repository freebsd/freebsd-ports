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
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://dickey.his.com/dialog/
DISTNAME=	${PORTNAME:S|^c||}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	alane@freebsd.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	makefile

MAN1=		dialog.1
MANLINKS=	dialog.1 cdialog.1

post-install:
	cd ${PREFIX}/bin; ${RM} -fv cdialog; ${LN} -fv dialog cdialog
	cd ${MANPREFIX}/man/man1; \
		${RM} -fv cdialog.1; ${LN} -fv dialog.1 cdialog.1

.include <bsd.port.mk>
#EOF
