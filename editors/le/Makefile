# New ports collection makefile for:	le
# Version required:			1.4.2
# Date created:				16 October 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/03/16 14:08:18 tg Exp $
#

DISTNAME=	le-1.4.2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.yars.free.net/pub/software/unix/util/texteditors/

MAINTAINER=	andy@icc.surw.chel.su

BROKEN=		build

GNU_CONFIGURE=	yes
MAN1=		le.1

post-install:
.for file in colors1 colors2 colors3
	@ ${INSTALL_DATA} ${WRKSRC}/misc/${file} ${PREFIX}/share/le
.endfor
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/le
.for file in FEATURES HISTORY NEWS README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/le
.endfor
.endif

.include <bsd.port.mk>
