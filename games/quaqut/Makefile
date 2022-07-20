PORTNAME=	quaqut
PORTVERSION=	0.2.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20C%20sources/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Queries information from Unreal Tournament 2004 game servers

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: quaqut
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: quaqut

HAS_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}
PORTDOCS=	AUTHORS COPYING ChangeLog README
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/quaqut.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
