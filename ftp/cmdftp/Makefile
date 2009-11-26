# New ports collection makefile for:	cmdftp
# Date created:		2003-12-28
# Whom:			Andreas Fehlner <fehlner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	cmdftp
PORTVERSION=	0.9.7
CATEGORIES=	ftp
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line shell-like ftp client

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
MAN1=	${PORTNAME}.1

PORTDOCS=	ChangeLog README INSTALL NEWS AUTHORS
PLIST_FILES=	bin/cmdftp

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_MAN} ${WRKSRC}/cmdftp.man ${MAN1PREFIX}/man/man1/${PORTNAME}.1
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
