# New ports collection makefile for:    cmdftp
# Date created:         2003-12-28
# Whom:                 Andreas Fehlner <fehlner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	cmdftp
PORTVERSION=	0.9.3
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Command line shell-like ftp client

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PORTDOCS=	ChangeLog README INSTALL NEWS COPYING AUTHORS
PLIST_FILES=	bin/cmdftp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
