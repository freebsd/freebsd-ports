# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	malint
DISTVERSION=	0.2
CATEGORIES=	audio
MASTER_SITES=	http://www.nih.at/malint/ \
		ftp://sunsite.univie.ac.at/pub/nih/malint/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	MPEG Audio stream validator

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

PORTDOCS=	README
PLIST_FILES=	bin/malint

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
