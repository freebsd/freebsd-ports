# New ports collection makefile for:	darcs
# Date created:				13 April 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darcs
PORTVERSION=	0.9.5
CATEGORIES=	devel
MASTER_SITES=	http://www.abridgegame.org/darcs/

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	Yet another replacement for CVS, written in Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_REINPLACE=	yes
USE_GMAKE=	yes
ALL_TARGET=	darcs darcs.1

GHC_VERSION=	`${PREFIX}/bin/ghc --version 2>&1 | \
			${SED} 's/^.*version[ ]*\([0-9.]*\).*/\1/'`

MAN1=	darcs.1

post-patch:
	@${REINPLACE_CMD} -e 's|<curl|<${PREFIX}/include/curl|' \
		${WRKSRC}/hscurl.c
	@${REINPLACE_CMD} -e \
		's|/usr/share/doc/darcs/manual/index.html|http://www.abridgegame.org/darcs/|' \
		${WRKSRC}/man.hs

do-configure:
	@${ECHO_CMD} PREFIX=${PREFIX} >> ${WRKSRC}/make.inc
	@${ECHO_CMD} CURL_STUFF = hscurl.c -lcurl -optl-pthread -L${PREFIX}/lib/ \
		>> ${WRKSRC}/make.inc
	@${ECHO_CMD} GHCINC=-I${PREFIX}/lib/ghc-${GHC_VERSION}/include >> ${WRKSRC}/make.inc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/darcs ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/darcs.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
