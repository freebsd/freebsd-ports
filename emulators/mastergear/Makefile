# New ports collection makefile for:   mastergear
# Version required:    1.0
# Date created:        02 November 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	MG12-FreeBSD-80x86-bin
PKGNAME=	mastergear-1.2
CATEGORIES=	emulators
MASTER_SITES=	http://www.komkon.org/fms/MG/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	nacai@iname.com

WRKSRC=		${WRKDIR}/SMS
ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
STRIP=
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mg ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/mastergear
	${INSTALL_DATA} ${WRKSRC}/MG.doc ${PREFIX}/share/mastergear

.include <bsd.port.mk>
