# ex:ts=8
# Ports collection makefile for:  xbill
# Date created:			  12 September 1995
# Whom:				  asami
#
# $FreeBSD$
#

PORTNAME=	xbill
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.xbill.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Save your computers from the evil clutches of Bill

SCORES_DIR?=	${DATADIR}/scores

USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
USE_XPM=	yes
USE_GNOME=	gtk12
CONFIGURE_ENV+=	PREFIX=${PREFIX}
CONFIGURE_ARGS+=--localstatedir=${SCORES_DIR}

MAN6=		xbill.6

.include <bsd.port.mk>
