# New ports collection makefile for:	FreeVision
# Date created: 			8 February 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

PORTNAME=	fvision
PORTVERSION=	1.0.10
CATEGORIES=	devel
MASTER_SITES=	http://www.borgsdemons.com/distfiles/
PKGNAMEPREFIX=	fpc-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeVision is a Free Pascal unit for Delphi support

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAKE_ENV+=	PATH=${LOCALBASE}/bin:$$PATH \
		FPC=${LOCALBASE}/bin/ppc386 \
		INSTALL_BASEDIR=${PREFIX}/lib/fpc/${PORTVERSION} \
		INSTALL_BINDIR=${PREFIX}/bin \
		GCCLIBDIR=/usr/lib \
		RELEASE=1

post-patch:
# change to alter amount of optimization
	@${FIND} ${WRKDIR}/fvision -name "Makefile*" | ${XARGS} \
		${REINPLACE_CMD} 's|-OG2p3|-OG2p1|g'

do-build:
	@${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKDIR}/fvision all

do-install:
	@${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKDIR}/fvision install
	cd ${WRKDIR}/fvision && ${INSTALL_DATA} \
		asciitab.o asciitab.ppu \
		${PREFIX}/lib/fpc/${PORTVERSION}/units/freebsd/fv

.include <bsd.port.post.mk>
