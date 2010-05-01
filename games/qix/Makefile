# New ports collection makefile for:    qix
# Date created:         6 June 2000
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	qix
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The classic arcade game

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
		xset:${PORTSDIR}/x11/xset

USE_DISPLAY=	yes

.if defined(WITHOUT_X11)
MAKE_ARGS=	NO_X11=yes
.else
USE_XORG=	x11
PLIST=		pkg-plist.x11
.endif

.if (!defined(DISPLAY) || ${DISPLAY} == "") && !defined(PACKAGE_BUILDING)
IGNORE=		requires an active X session (and DISPLAY variable) to run xrdb.  Please compile this while running X
.endif

MAN1=		qix.1

FONTSDIR=	lib/X11/fonts/local
PLIST_SUB=	FONTSDIR=${FONTSDIR}

do-configure:
	@${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile~
	${SED} -e s:/usr/local:${PREFIX}: -e s:/usr/X11R6:${PREFIX}: \
	  < ${WRKSRC}/Makefile~ > ${WRKSRC}/Makefile

.include <bsd.port.mk>
