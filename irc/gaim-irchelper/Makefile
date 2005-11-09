# New ports collection makefile for:	gaim-irchelper
# Date created:		2005-09-04
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gaim-irchelper
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	irc net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Gaim plugin that enhances the usability of the IRC protocol

BUILD_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net-im/gaim

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
PLIST_FILES=	lib/gaim/irchelper.so

.include <bsd.port.mk>
