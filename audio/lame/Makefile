# ports collection makefile for:   lame
# Version required:    3.11
# Date created:        11 January 1998
# Whom:                yoshiaki Uchikawa
#
# $Id$
#

DISTNAME=	lame3.11
PKGNAME=	lame-3.11
CATEGORIES=	audio
MASTER_SITES=	ftp://geek.rcc.se/pub/mp3encoder/lame/

MAINTAINER=	yoshiaki@kt.rim.or.jp

LIB_DEPENDS=	gtk12:${PORTSDIR}/x11-toolkits/gtk12

MAN1=		lame.1

USE_GMAKE=	YES
ALL_TARGET=	lame
RESTRICTED=	Condition is not clear

do-install:
	( cd ${WRKSRC}; ${INSTALL_PROGRAM} lame ${PREFIX}/bin )
	( cd ${WRKSRC}; ${INSTALL_MAN} ${WRKSRC}/doc/man/lame.1 \
	${PREFIX}/man/man1 )

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/lame
	${INSTALL_MAN} ${WRKSRC}/doc/html/* ${PREFIX}/share/doc/lame
.endif

.include <bsd.port.mk>
