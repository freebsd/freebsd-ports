# New ports collection makefile for:	dict-zh
# Date created:		25 Oct 1999
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dictd-database
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	chinese textproc
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/dictd-database/
DISTNAME=	dict-zh-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Chinese <-> English dictd words database

BUILD_DEPENDS=	${LOCALBASE}/bin/dictzip:${PORTSDIR}/chinese/dictd

USE_LIBTOOL_VER=	13
USE_GMAKE=	yes
USE_PERL5_BUILD=yes

post-install:
	@${SED} -e 's,PREFIX,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
