# Ports collection makefile for:	cdict
# Date created:                         Thu Oct 14, 1999
# Whom:                                 Peng HaiJie   (phj@cn.FreeBSD.org)
#                                       (phj@transfar.com)
#
# $FreeBSD$
#

PORTNAME=	stardict
PORTVERSION=	1.3
CATEGORIES=	chinese
MASTER_SITES=	ftp://ftp.cn.FreeBSD.org/pub/ported/
PKGNAMEPREFIX=	zh-
DISTNAME=	${PKGNAME}

MAINTAINER=	phj@cn.FreeBSD.org

USE_MOTIF=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

port-install:
	strip	$(PREFIX)/bin/${PORTNAME}

.include <bsd.port.mk>
