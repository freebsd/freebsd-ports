# New ports collection makefile for:	kterm
# Version required:	6.2
# Date created:		18 November 1994
# Whom:			asami
#
# $Id: Makefile,v 1.11 1996/11/01 13:43:14 asami Exp $
#

DISTNAME=	kterm-6.2.0
PKGNAME=	jp-kterm-6.2.0
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/

MAINTAINER=	asami@FreeBSD.ORG

USE_IMAKE=	yes

.if exists(/usr/X11R6/lib/libXaw3d.a) && !defined(PACKAGE_BUILDING)
post-patch:
	@${ECHO_MSG}  "===>  Applying Xaw3d scrollbar patch"
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-0
.endif

.include <bsd.port.mk>
