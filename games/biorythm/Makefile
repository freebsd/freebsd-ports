# New ports collection makefile for:	biorythm
# Version required:			1.1.1
# Date created:				4 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		biorythm-1.1.1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SUNSITE} \
			http://home.sol.no/~sverrehu/pub-unix/files/
MASTER_SITE_SUBDIR=	games/amusements

MAINTAINER=		andy@icc.surw.chel.su

LIB_DEPENDS=		shhmsg.1:${PORTSDIR}/devel/libshhmsg \
			shhopt.1:${PORTSDIR}/devel/libshhopt

USE_GMAKE=		yes

MAN6=			biorythm.6

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/biorythm ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/biorythm.6 ${PREFIX}/man/man6

post-install:
.if !defined (NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/biorythm
.for file in CREDITS ChangeLog README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/biorythm
.endfor
.endif

.include <bsd.port.mk>
