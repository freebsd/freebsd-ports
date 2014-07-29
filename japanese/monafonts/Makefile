# Created by: MANTANI Nobutaka <nobutaka@nobutaka.com>
# $FreeBSD$

PORTNAME=	monafonts
PORTVERSION=	2.90
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	SF/monafont/monafont/monafont-${PORTVERSION}
DISTNAME=	monafont-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	X11 12,14,16-dot Kanji fonts

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

USES=		perl5 tar:bzip2
USE_PERL5=	build

FONTSDIR=	lib/X11/fonts/local
ALL_TARGET=	bdf

PLIST_SUB=	FONTSDIR=${FONTSDIR}

.include <bsd.port.mk>
