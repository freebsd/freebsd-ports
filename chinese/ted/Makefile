# New ports collection makefile for:	ted
# Version required:	4.2c
# Date Created:		18 Sep 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.8 1998/01/19 13:11:50 vanilla Exp $
#

DISTNAME=		ted4.2c
PKGNAME=		zh-ted-4.2c
CATEGORIES=		chinese editors
MASTER_SITES=		ftp://moon.csie.ntu.edu.tw/pub/X/ted/ \
			ftp://freebsd.ntu.edu.tw/freebsd/ntu/moon/X/ted/
EXTRACT_SUFX=		.tgz

MAINTAINER=		vanilla@FreeBSD.ORG

RUN_DEPENDS=		${X11BASE}/bin/xcin:${PORTSDIR}/chinese/xcin

BROKEN=			package

USE_X11=		yes
WRKSRC=			${WRKDIR}/ted

.include <bsd.port.mk>
