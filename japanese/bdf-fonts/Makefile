# Ports collection makefile for: Japanese Font Setup
# Date created:		14 Jan 2002
# Whom:			KOMATSU Shinichiro
#
# $FreeBSD$
#

PORTNAME=	bdf-fonts
PORTVERSION=	1.0
CATEGORIES=	japanese x11-fonts
DISTFILES=	# empty

MAINTAINER=	koma2@jiro.c.u-tokyo.ac.jp

RUN_DEPENDS=	\
	${FONTSDIR}/jpnhn4-iso.pcf.gz:${PORTSDIR}/japanese/elisa8x8 \
	${FONTSDIR}/5x10B.pcf.gz:${PORTSDIR}/japanese/k10 \
	${FONTSDIR}/shnmk12.pcf.gz:${PORTSDIR}/japanese/shinonome \
	${FONTSDIR}/kanji18.pcf.gz:${PORTSDIR}/japanese/kanji18 \
	${FONTSDIR}/k20b.pcf.gz:${PORTSDIR}/japanese/kappa20 \
	${FONTSDIR}/kanji26.pcf.gz:${PORTSDIR}/japanese/kanji26 \
	${FONTSDIR}/K12-1.pcf.gz:${PORTSDIR}/japanese/jisx0213-fonts

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
RUN_DEPENDS+=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

FONTSDIR=	${X11BASE}/lib/X11/fonts/local
NO_BUILD=	yes

do-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${PERL} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
