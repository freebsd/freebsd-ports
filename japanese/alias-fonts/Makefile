# Ports collection makefile for: Japanese Font Setup
# Date created:		22 Jun 1998
# Whom:                 sada
#
# $FreeBSD$
#

PORTNAME=	alias-fonts
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	japanese x11-fonts
DISTFILES=	# empty

MAINTAINER=	koma2@lovepeers.org
COMMENT=	A meta-port which setups Japanese fonts

RUN_DEPENDS=	\
		${FONTSDIR}/jpnhn4-iso.pcf.gz:${PORTSDIR}/japanese/elisa8x8 \
		${FONTSDIR}/5x10B.pcf.gz:${PORTSDIR}/japanese/k10 \
		${LOCALBASE}/share/font-shinonome/shnmk12.pcf.gz:${PORTSDIR}/japanese/font-shinonome \
		${FONTSDIR}/kanji18.pcf.gz:${PORTSDIR}/japanese/kanji18 \
		${FONTSDIR}/k20b.pcf.gz:${PORTSDIR}/japanese/kappa20 \
		${FONTSDIR}/kanji26.pcf.gz:${PORTSDIR}/japanese/kanji26 \
		${FONTSDIR}/K12-1.pcf.gz:${PORTSDIR}/japanese/jisx0213-fonts
BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

NO_BUILD=	yes
USE_PERL5=	yes

FONTSDIR=	${LOCALBASE}/lib/X11/fonts/local

do-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${PERL} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
