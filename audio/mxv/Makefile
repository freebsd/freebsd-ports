# New ports collection makefile for:	mxv
# Date created:		17 March 1997
# Whom:			davidn@blaze.net.au
#
# $FreeBSD$
#

PORTNAME=	mxv
PORTVERSION=	1.20
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.create.ucsb.edu/pub/MixViews/source/
DISTNAME=	${PORTNAME}-v${PORTVERSION}-source

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Sound file editor/player/recorder/converter for X Window System

BROKEN=		"Does not build"

BUILD_DEPENDS=	${LOCALBASE}/interviews/bin/FREEBSD/ivmkmf:${PORTSDIR}/x11-toolkits/iv

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes
MAKE_ENV=	CPU=FREEBSD
#ivmkmf -a (with makedepend) not recommended by documentation
XMKMF=		${SETENV} ${MAKE_ENV} ${LOCALBASE}/interviews/bin/FREEBSD/ivmkmf; \
		${SETENV} ${MAKE_ENV} make Makefiles

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/FREEBSD/mxv ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/MiXViews.res ${PREFIX}/lib/X11/app-defaults/MiXViews

.include <bsd.port.mk>
