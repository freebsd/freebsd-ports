# New ports collection makefile for:   mastergear
# Version required:    0.8
# Date created:        02 November 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	SMS
PKGNAME=        mastergear-0.8
CATEGORIES=     emulators
MASTER_SITES=   ftp://freefall.freebsd.org/pub/FreeBSD/LOCAL_PORTS/
DISTFILES=	MG.tar.Z

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

USE_X11=	yes

CONFIGURE_ENV+=	X11BASE=${X11BASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mg ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dasm ${PREFIX}/bin
	@mkdir ${PREFIX}/share/mastergear
	cp ${WRKSRC}/MG.doc ${PREFIX}/share/mastergear

.include <bsd.port.mk>

