# New ports collection makefile for:   mastergear
# Date created:        02 November 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	mastergear
PORTVERSION=	1.3
CATEGORIES=	emulators
MASTER_SITES=	http://fms.komkon.org/MG/
DISTNAME=	MG13-FreeBSD-80x86-bin
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	nakai@FreeBSD.org

NO_WRKSUBDIR=	yes
ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
STRIP=
USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mg ${PREFIX}/bin
.if(!defined(NOPORTDOCS))
	@${MKDIR} ${PREFIX}/share/mastergear
	${INSTALL_DATA} ${WRKSRC}/MG.html ${PREFIX}/share/mastergear
.endif

.include <bsd.port.mk>
