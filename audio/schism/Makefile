# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	schism
PORTVERSION=	20100101
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://schismtracker.org/dl/ \
		CRITICAL
DISTNAME=	schismtracker-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Module tracker editor/player resembling impulse tracker

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	i386 amd64

USES=		tar:bzip2
USE_SDL=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME}

WRKSRC=		${WRKDIR}/${DISTNAME}

# releases up to version 20120105 either segfault or don't run
PORTSCOUT=	skipv:20100202,20101127,20101128,20110101,20120105

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/schismtracker ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.pre.mk>

# after merging log2 and log2f into libm
.if ${OSVERSION} >= 802502
EXTRA_PATCHES=	${FILESDIR}/extrapatch-modplug__snd_gm.c
.endif

.include <bsd.port.post.mk>
