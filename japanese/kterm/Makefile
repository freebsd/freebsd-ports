# New ports collection makefile for:	kterm
# Version required:	6.2
# Date created:		18 November 1994
# Whom:			asami
#
# $Id: Makefile,v 1.14 1997/09/14 21:34:51 max Exp $
#

DISTNAME=	kterm-6.2.0
PKGNAME=	ja-kterm-6.2.0
CATEGORIES=	japanese x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

PATCH_SITES=	ftp://ftp.sra.co.jp/pub/x11/kterm/
PATCHFILES=	kterm-6.2.0.NFS-xauth.patch

MAINTAINER=	asami@FreeBSD.ORG

USE_IMAKE=	yes

.if exists(/usr/X11R6/lib/libXaw3d.a) && !defined(PACKAGE_BUILDING)
post-patch:
	@${ECHO_MSG}  "===>  Applying Xaw3d scrollbar patch"
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-0
.endif

.include <bsd.port.mk>
