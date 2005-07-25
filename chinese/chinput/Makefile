# ex:ts=8
# Ports collection makefile for:  chinput
# Date created:                          09/07/2000
# Whom:                                  Peng HaiJie   (phj@cn.freebsd.org)
#
# $FreeBSD$
#

PORTNAME=	chinput
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	chinese x11
MASTER_SITES=	ftp://ftp.cn.freebsd.org/pub/ported/
DISTNAME=	zh-chinput-2.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chinese GB2312,BIG5,Japanese code input server

BUILD_DEPENDS=	xmkmf:${X_IMAKE_PORT} \
		mkfontdir:${X_CLIENTS_PORT}

BROKEN=		Incomplete pkg-plist
DEPRECATED=	"${BROKEN}"
EXPIRATION_DATE=2005-09-22

USE_XLIB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-extract:
	${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -rf

.include <bsd.port.mk>
