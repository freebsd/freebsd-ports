# New ports collection makefile for:	ted
# Version required:	4.3b
# Date Created:		18 Sep 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.19 1998/11/19 16:36:40 vanilla Exp $
#

DISTNAME=		ted4.3b
PKGNAME=		zh-ted-4.3b
CATEGORIES=		chinese editors
MASTER_SITES=		ftp://moon.csie.ntu.edu.tw/pub/X/ted/ \
			ftp://freebsd.ntu.edu.tw/freebsd/ntu/moon/X/ted/
EXTRACT_SUFX=		.tgz

MAINTAINER=		vanilla@FreeBSD.ORG

RUN_DEPENDS=		${X11BASE}/bin/xcin:${PORTSDIR}/chinese/xcin

USE_X_PREFIX=		yes
WRKSRC=			${WRKDIR}/ted

.include <bsd.port.mk>
