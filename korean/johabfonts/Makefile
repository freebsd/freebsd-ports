# New ports collection makefile for:	johabfonts
# Date created:		15 Mar 1998
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	johabfonts
PORTVERSION=	3.1
PORTREVISION=	2
CATEGORIES=	korean x11-fonts
MASTER_SITES=	http://hanterm.org/download/font/
DISTNAME=	hanterm-font-${PORTVERSION}

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Hangul fonts for X11(johab) used in many hangul-related programs

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

USE_IMAKE=	yes

NO_INSTALL_MANPAGES= yes
WRKSRC=		${WRKDIR}/hanterm-font/10-6-6

pre-install:
	-${MKDIR} ${PREFIX}/lib/X11/fonts/local

.include <bsd.port.mk>
