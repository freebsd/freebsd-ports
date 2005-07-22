# New ports collection makefile for:    cmdftp
# Date created:         2003-12-28
# Whom:                 Andreas Fehlner <fehlner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	cmdftp
PORTVERSION=	0.9.2
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cmdftp

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Command line shell-like ftp client

USE_REINPLACE=yes
GNU_CONFIGURE=yes
USE_GMAKE=yes

DOCS=	ChangeLog README INSTALL NEWS COPYING AUTHORS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmdftp ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
