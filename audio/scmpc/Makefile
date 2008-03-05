# New ports collection makefile for:	scmpc
# Date created:				January 16, 2008
# Whom:					Pavel Motyrev <legioner.r@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	scmpc
PORTVERSION=	0.2.2
CATEGORIES=	audio
MASTER_SITES=	BERLIOS

MAINTAINER=	legioner.r@gmail.com
COMMENT=	An Audioscrobbler client for MPD

LIB_DEPENDS=	argtable2.1:${PORTSDIR}/devel/argtable \
		confuse.0:${PORTSDIR}/devel/libconfuse \
		daemon.0:${PORTSDIR}/devel/libdaemon \
		curl.4:${PORTSDIR}/ftp/curl

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		scmpc.1
PLIST_FILES=	bin/scmpc share/scmpc/scmpc.conf
PLIST_DIRS=	share/scmpc

.include <bsd.port.mk>
