# New ports collection makefile for:	XFree86 3.3.6 aout libs
# Date created:		31 Oct 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD: /tmp/pcvs/ports/chinese/XFree86-aoutlibs/Attic/Makefile,v 1.4 2001-03-02 17:43:02 keith Exp $
#

# The file is identical to
# ftp://ftp.xfree86.org/pub/XFree86/3.3.6/binaries/FreeBSD-2.2.x/Xbin.tgz
# Renamed to avoid distfiles conflict with x11/XFree86-aoutlibs.

PORTNAME=	XFree86-aoutlibs
PORTVERSION=	3.3.6
CATEGORIES=	x11
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/
DISTNAME=	Xbin336aout
EXTRACT_SUFX=	.tgz

MAINTAINER=	keith@FreeBSD.org

RUN_DEPENDS=	${X11BASE}/lib/aout/libX11.so.6.1:${PORTSDIR}/x11/XFree86-aoutlibs

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/lib
NO_BUILD=	yes
PORTOBJFORMAT=	aout

USE_X_PREFIX=	yes

pre-configure:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGREQ} ${PKGNAME} INSTALL

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${PREFIX}/lib/aout
	cd ${WRKSRC}; \
	for l in $$(ls lib*); do \
		${SETENV} OBJFORMAT=${PORTOBJFORMAT} \
		${INSTALL_PROGRAM} $$l ${PREFIX}/lib/aout; \
	done
	${TOUCH} ${PREFIX}/lib/aout/zh-XFree86-aoutlibs-3.3.6
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib/aout

.include <bsd.port.mk>
