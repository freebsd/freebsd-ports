# New ports collection makefile for:	darcs
# Date created:				13 April 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darcs
PORTVERSION=	0.9.9
CATEGORIES=	devel
MASTER_SITES=	http://www.abridgegame.org/darcs/

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	Yet another replacement for CVS, written in Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USE_REINPLACE=	yes
USE_GMAKE=	yes
ALL_TARGET=	darcs darcs.1 darcs-patcher darcs-createrepo

GHC_VERSION=	`${PREFIX}/bin/ghc --version 2>&1 | \
			${SED} 's/^.*version[ ]*\([0-9.]*\).*/\1/'`

.if defined(WITH_CGI)
ALL_TARGET+=	darcs_cgi
.if !exists(${PREFIX}/www) && exists(${PREFIX}/share/apache)
CGIDIR?=	share/apache/cgi-bin
.else
CGIDIR?=	www/cgi-bin
.endif
PLIST_SUB+=	CGIDIR=${CGIDIR}
.else
PLIST_SUB+=	CGIDIR="@comment "
.endif

MAN1=	darcs.1

pre-everything::
.if !defined(WITH_CGI)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "To build and install the cgi script define WITH_CGI."
	@${ECHO_CMD} ""
.endif

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
	${INSTALL_PROGRAM} ${WRKSRC}/darcs-patcher ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/darcs-createrepo ${PREFIX}/bin
.if defined(WITH_CGI)
	${MKDIR} ${PREFIX}/${CGIDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/darcs_cgi ${PREFIX}/${CGIDIR}/darcs
.endif

.include <bsd.port.mk>
