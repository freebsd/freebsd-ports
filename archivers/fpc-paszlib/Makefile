# New ports collection makefile for:	FreeVision
# Date created: 			9 February 2004
# Whom: 				John Merryweather Cooper
#
# $FreeBSD$
#

PORTNAME=	paszlib
PORTVERSION=	1.0.10
CATEGORIES=	archivers devel
MASTER_SITES=	http://www.borgsdemons.com/distfiles/
PKGNAMEPREFIX=	fpc-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Pascal unit for native compression IO

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

PLIST_SUB+=	INSTDIR=lib/fpc/${PORTVERSION}/units/freebsd/paszlib \
		PORTVERSION=${PORTVERSION}

MAKE_ENV+=	PATH=${LOCALBASE}/bin:$$PATH \
		FPC=${LOCALBASE}/bin/ppc386 \
		INSTALL_BASEDIR=${PREFIX}/lib/fpc/${PORTVERSION} \
		INSTALL_BINDIR=${PREFIX}/bin \
		GCCLIBDIR=/usr/lib \
		RELEASE=1

post-patch:
# change to alter amount of optimization
	@${FIND} ${WRKDIR}/paszlib -name "Makefile*" | ${XARGS} \
		${REINPLACE_CMD} 's|-OG2p3|-OG2p1|g'

do-build:
	@${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKDIR}/paszlib all

do-install:
	@${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKDIR}/paszlib install

.include <bsd.port.post.mk>
