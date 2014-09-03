# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gqlplus
PORTVERSION=	1.16
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	SQL*PLUS with commandline editing, history, and name completion

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		gmake readline

PORTDOCS=	README ChangeLog
PLIST_FILES=	bin/gqlplus
USE_AUTOTOOLS=	autoconf automake aclocal
AUTOMAKE_ARGS=	--add-missing

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
