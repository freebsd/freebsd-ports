# New ports collection makefile for:	namazu
# Version required:	1.3.0.6
# Date created:		17 March 1998
# Whom:			Seiichirou Hiraoka
#
# $Id: Makefile,v 1.1.1.1 1999/03/31 11:52:07 flathill Exp $
#

DISTNAME=	namazu-1.3.0.8
PKGNAME=	ja-namazu-1.3.0.8
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/namazu/release/

MAINTAINER=	flathill@FreeBSD.ORG

BUILD_DEPENDS=	kakasi:${PORTSDIR}/japanese/kakasi \
		nkf:${PORTSDIR}/japanese/nkf
RUN_DEPENDS=	kakasi:${PORTSDIR}/japanese/kakasi \
		nkf:${PORTSDIR}/japanese/nkf

USE_PERL5=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/namazu-1.3.0.8/src

.include <bsd.port.mk>
