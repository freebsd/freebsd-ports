# New ports collection makefile for:	hexedit
# Version required:			1.0.0
# Date created:				5 August 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.3 1998/10/09 10:05:49 asami Exp $
#

DISTNAME=		hexedit-1.0.0
CATEGORIES=		editors
MASTER_SITES=		http://www.chez.com/prigaux/ \
			${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file/hex
EXTRACT_SUFX=		.src.tgz

MAINTAINER=		andy@icc.surw.chel.su

USE_AUTOCONF=		yes

ALL_TARGET=
WRKSRC=			${WRKDIR}/hexedit

MAN1=			hexedit.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/hexedit ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/hexedit.1 ${PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/hexedit
.for file in COPYING Changes TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/hexedit
.endfor
.endif

.include <bsd.port.mk>
