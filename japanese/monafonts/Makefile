# New ports collection makefile for:	monafonts
# Date created:		14 February 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	monafonts
PORTVERSION=	2.90
PORTEPOCH=	2
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	monafont
DISTNAME=	monafont-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	X11 12,14,16-dot kanji fonts

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}
USE_PERL5_BUILD=yes

FONTSDIR=	lib/X11/fonts/local
USE_BZIP2=	yes
USE_X_PREFIX=	yes
ALL_TARGET=	bdf
MAKE_ARGS=	PREFIX=${PREFIX}

PLIST_SUB=	FONTSDIR=${FONTSDIR}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

.include <bsd.port.mk>
