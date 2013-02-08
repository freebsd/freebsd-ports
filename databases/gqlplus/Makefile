# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$
#

PORTNAME=	gqlplus
PORTVERSION=	1.15
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	SQL*PLUS with commandline editing, history, and name completion

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PORTDOCS=	README ChangeLog
PLIST_FILES=	bin/gqlplus
USE_AUTOTOOLS=	autoconf automake aclocal

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
