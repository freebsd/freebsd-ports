# New ports collection makefile for:	namazu
# Version required:	1.3.0.6
# Date created:		17 March 1998
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

DISTNAME=	namazu-1.3.0.8
PKGNAME=	ja-namazu-1.3.0.8
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/namazu/release/

MAINTAINER=	flathill@FreeBSD.org

BUILD_DEPENDS=	kakasi:${PORTSDIR}/japanese/kakasi \
		nkf:${PORTSDIR}/japanese/nkf
RUN_DEPENDS=	kakasi:${PORTSDIR}/japanese/kakasi \
		nkf:${PORTSDIR}/japanese/nkf

USE_PERL5=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/namazu-1.3.0.8/src

.include <bsd.port.mk>
