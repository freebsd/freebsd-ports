# New ports collection makefile for:   mastergear
# Version required:    0.8
# Date created:        02 November 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.2 1996/12/05 11:04:42 asami Exp $
#

DISTNAME=	SMS
PKGNAME=        mastergear-0.8
CATEGORIES=     emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	MG.tar.Z

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

USE_X11=	yes

CONFIGURE_ENV+=	X11BASE=${X11BASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mg ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dasm ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/mastergear
	${INSTALL_DATA} ${WRKSRC}/MG.doc ${PREFIX}/share/mastergear

.include <bsd.port.mk>

