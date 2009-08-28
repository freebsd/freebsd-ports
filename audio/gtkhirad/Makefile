# New ports collection makefile for:   gtkhirad
# Date created:                2007/06/10
# Whom:                        chinsan
#
# $FreeBSD$
#

PORTNAME=	gtkhirad
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	audio chinese gnome
MASTER_SITES=	http://pcman.sayya.org/gtkhirad/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hinet Radio player using GTK

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget \
		mplayer:${PORTSDIR}/multimedia/mplayer

USE_BZIP2=	yes
USE_GNOME=	gtk20 intlhack
USE_GMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes

MAKE_ARGS=	prefix=${PREFIX}

.include <bsd.port.mk>
