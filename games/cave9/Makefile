# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cave9
PORTVERSION=	0.4
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}_src-${PORTVERSION}
DISTFILES=	${DISTNAME}.tgz \
		${PORTNAME}_data-${DATAVER}.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Gravity cave-exploration game

DATAVER=	4

USE_GMAKE=	yes
USE_SDL=	sdl ttf image

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src

MAKEFILE=	GNUmakefile
CFLAGS+=	-DDATADIR=\\\"${DATADIR}\\\"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-extract:
	@${MV} ${WRKDIR}/data ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cave9 ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/* ${STAGEDIR}${DATADIR}/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
