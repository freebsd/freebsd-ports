# New ports collection makefile for:	dict-zh
# Date created:		25 Oct 1999
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dictd-database
PORTVERSION=	1.3
CATEGORIES=	chinese textproc
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/dictd-database/
DISTNAME=	dict-zh-${PORTVERSION}

MAINTAINER=	statue@freebsd.sinica.edu.tw

BUILD_DEPENDS=  ${LOCALBASE}/bin/dictzip:${PORTSDIR}/chinese/dictd

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
