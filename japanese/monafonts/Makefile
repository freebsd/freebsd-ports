# New ports collection makefile for:	monafonts
# Date created:		14 February 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	monafonts
PORTVERSION=	2.22
PORTEPOCH=	2
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	monafont
DISTNAME=	monafont-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org

FONTSDIR=	lib/X11/fonts/local
USE_BZIP2=	yes
USE_X_PREFIX=	yes
ALL_TARGET=	bdf
MAKE_ARGS=	PREFIX=${PREFIX}
.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

PLIST_SUB=	FONTSDIR=${FONTSDIR}

post-extract:
	@${MKDIR} ${WRKSRC}/dist

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGREQ} ${PKGNAME} INSTALL

.include <bsd.port.post.mk>
