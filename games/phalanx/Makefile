# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	phalanx
PORTVERSION=	25
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Version%20XXV
DISTNAME=	${PORTNAME}-XXV-source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xboard-compatible chess playing program

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${DISTNAME:S/p/P/:S/-source//}

USES=		gmake tar:tgz
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	# empty
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-DECO_DIR=\\\"${DATADIR}\\\" \
		-DLEARN_DIR=\\\"${DATADIR}\\\" \
		-DPBOOK_DIR=\\\"${DATADIR}\\\" \
		-DSBOOK_DIR=\\\"${DATADIR}\\\"

PORTDOCS=	HISTORY README
PLIST_FILES=	bin/phalanx \
		%%DATADIR%%/eco.phalanx \
		%%DATADIR%%/pbook.phalanx \
		%%DATADIR%%/sbook.phalanx

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/phalanx ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.phalanx ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/${file}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
