# New ports collection makefile for:   gogo no coder
# Version required:    1999-07-09
# Date created:        01 July 1999
# Whom:                Yukihiro Nakai <Nacai@iname.com>
#
# $FreeBSD$
#

DISTNAME=	bsd0709
PKGNAME=	gogo-19990709
CATEGORIES=	audio
MASTER_SITES=	http://www.kurims.kyoto-u.ac.jp/~shigeo/soft/mpegenc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	Nacai@iname.com

WRKSRC=		${WRKDIR}

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gogo ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/gogo
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/doc/gogo

.include <bsd.port.mk>
