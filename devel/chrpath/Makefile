# New ports collection makefile for:	chrpath
# Date created:		2009-12-01
# Whom:			bms
#
# $FreeBSD$
#

PORTNAME=	chrpath
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	devel sysutils
MASTER_SITES=	http://ftp.tux.org/pub/X-Windows/ftp.hungry.com/chrpath/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to modify DT_RPATH in existing ELF binaries

GNU_CONFIGURE=	yes

MAN1=		chrpath.1

PLIST_FILES=    bin/chrpath

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.	for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.	endfor
.endif


.include <bsd.port.mk>
