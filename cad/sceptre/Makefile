# New ports collection makefile for:	sceptre
# Date created:		11 February 2001
# Whom:			grog
#
# $FreeBSD$
#

PORTNAME=	sceptre
PORTVERSION=	00.317
PORTREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://ftp.osuosl.org/pub/FreeBSD/distfiles/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	SCEPTRE is a general purpose circuit analysis program

.if !defined(NOPORTDOCS)
SUB_FILES+=	pkg-message
.endif

.include <bsd.port.pre.mk>

USE_FORTRAN=	g77
FFLAGS+=	-fno-automatic -O
.if ${ARCH} == "sparc64"
BROKEN=		Internal compiler error
.endif

NO_WRKSUBDIR=	YES

post-extract:
	@${REINPLACE_CMD} 's,INSTDIR = /usr/local,INSTDIR = ${PREFIX},' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -o ${DOCOWN} -g ${DOCGRP} -m 555 -d ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DOCSDIR}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
