# ex:ts=8
# Ports collection makefile for:  chinput
# Date created:                          09/07/2000
# Whom:                                  Peng HaiJie   (phj@cn.freebsd.org)
#
# $FreeBSD$
#

PORTNAME=	chinput
PORTVERSION=	2.1
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://ftp.cn.freebsd.org/pub/ported/
DISTNAME=	zh-chinput-2.1

MAINTAINER=	phj@cn.FreeBSD.org

BROKEN=		"Patch fails"

WRKSRC=		${WRKDIR}/${PORTNAME}

post-extract:
	find ${WRKSRC} -name CVS | xargs ${RM} -rf

.include <bsd.port.mk>
