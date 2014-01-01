# Created by: TAKATSU Tomonari <tota@rtfm.jp>
# $FreeBSD$

PORTNAME=	silentbob
PORTVERSION=	3.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2/${PORTNAME}-${PORTVERSION:C@\.[0-9]+$@@}/

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Yet another sourcecode indexing tool

LICENSE=	GPLv2

USES=		cmake:outsource

PORTDOCS=	README
PLIST_FILES=	bin/silentbob

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${RM} ${WRKSRC}/CMakeCache.txt
	@${REINPLACE_CMD} -e 's|/usr/lib/silent_bob/|${PREFIX}/lib/silent_bob/|' \
		${WRKSRC}/src/init.cxx

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
