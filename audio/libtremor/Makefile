# Created by: kwm@rainbow-runner.nl
# $FreeBSD$

PORTNAME=	libtremor
PORTVERSION=	1.2.0.s20040213
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://members.chello.nl/~g.mast/distfiles/
DISTNAME=	tremor_snapshot_${SNAP_DATE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Integer-only fully Ogg Vorbis compliant decoder library

SNAP_DATE=	02132004
WRKSRC=		${WRKDIR}/Tremor
USES=		libtool tar:tgz
USE_AUTOTOOLS=	aclocal automake autoconf libtoolize
AUTOMAKE_ARGS=	-a -c
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
