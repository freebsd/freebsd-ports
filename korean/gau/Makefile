# New ports collection makefile for:    gau
# Date created:         23 Jul 1998
# Whom:                 CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gau
PORTVERSION=	0.4.1
PORTREVISION=	3
CATEGORIES=	korean comms
MASTER_SITES=	http://www.kr.freebsd.org/~hwang/gau/

PATCH_SITES=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/
PATCHFILES=	gau-0.4.1.patch gau-0.4.1-rc.patch gau-0.4.1-grim_show.patch \
		gau-0.4.1-script.patch gau-0.4.1-warning.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Gtk-based Hangul terminal emulator (for modem/tcp)

RUN_DEPENDS=	lrz:${PORTSDIR}/comms/lrzsz \
		${X11BASE}/lib/X11/fonts/local/gulim12.pcf.gz:${PORTSDIR}/korean/baekmukfonts-bdf

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

.include <bsd.port.post.mk>
