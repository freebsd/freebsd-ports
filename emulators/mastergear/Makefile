# New ports collection makefile for:   mastergear
# Version required:    1.0
# Date created:        02 November 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.5 1998/01/25 17:03:52 steve Exp $
#

DISTNAME=	SMS
PKGNAME=        mastergear-1.0
CATEGORIES=     emulators
MASTER_SITES=	http://www.komkon.org/fms/MG/
DISTFILES=	MG.tar.Z

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mg ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dasm ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/mastergear
	${INSTALL_DATA} ${WRKSRC}/MG.doc ${PREFIX}/share/mastergear

.include <bsd.port.mk>

