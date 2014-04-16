# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	quaqut
PORTVERSION=	0.2.0
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20C%20sources/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Queries information from Unreal Tournament 2004 game servers

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
