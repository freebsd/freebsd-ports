# New ports collection makefile for:	ted
# Version required:	4.2h
# Date Created:		18 Sep 1997
# Whom:			Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.13 1998/05/14 09:34:13 vanilla Exp $
#

DISTNAME=		ted4.2h
PKGNAME=		zh-ted-4.2h
CATEGORIES=		chinese editors
MASTER_SITES=		ftp://moon.csie.ntu.edu.tw/pub/X/ted/ \
			ftp://freebsd.ntu.edu.tw/freebsd/ntu/moon/X/ted/
EXTRACT_SUFX=		.tgz

MAINTAINER=		vanilla@FreeBSD.ORG

RUN_DEPENDS=		${X11BASE}/bin/xcin:${PORTSDIR}/chinese/xcin

USE_X11=		yes
WRKSRC=			${WRKDIR}/ted

.include <bsd.port.mk>
