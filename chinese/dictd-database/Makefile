# New ports collection makefile for:	dict-zh
# Date created:		25 Oct 1999
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dictd-database
PORTVERSION=	1.1
CATEGORIES=	chinese textproc
MASTER_SITES=	http://freebsd.sinica.edu.tw/~statue/
DISTNAME=	dict-zh-${PORTVERSION}

MAINTAINER=	statue@freebsd.sinica.edu.tw

BUILD_DEPENDS=  ${LOCALBASE}/bin/dictzip:${PORTSDIR}/net/dictd

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
