# Created by: Yoshiro MIHIRA <sanpei@jp.FreeBSD.org>
# $FreeBSD$

PORTNAME=	ngraph-fonts
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	japanese math x11-fonts
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Japanese Font Setup for math/ngraph

RUN_DEPENDS= \
	${LOCALBASE}/lib/X11/fonts/local/kanji18.pcf.gz:${PORTSDIR}/japanese/kanji18 \
	${LOCALBASE}/lib/X11/fonts/local/kanji26.pcf.gz:${PORTSDIR}/japanese/kanji26

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

NO_BUILD=	yes

do-install:	# empty

NO_STAGE=	yes
.include <bsd.port.mk>
