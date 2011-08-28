# New ports collection makefile for:	phalanx
# Date created:				2 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	phalanx
PORTVERSION=	23.b
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Version%20XXIII%20Beta
DISTNAME=	${PORTNAME}-XXIII-beta
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xboard-compatible chess playing program

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${DISTNAME:S/-beta//}

USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
ALL_TARGET=	# empty
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-DECO_DIR=\\\"${DATADIR}\\\" \
		-DLEARN_DIR=\\\"${DATADIR}\\\" \
		-DPBOOK_DIR=\\\"${DATADIR}\\\" \
		-DSBOOK_DIR=\\\"${DATADIR}\\\"

PORTDOCS=	HISTORY README README.old
PLIST_FILES=	bin/phalanx \
		%%DATADIR%%/eco.phalanx \
		%%DATADIR%%/pbook.phalanx \
		%%DATADIR%%/sbook.phalanx
PLIST_DIRS=	%%DATADIR%%

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/phalanx ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.phalanx ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
