# New ports collection makefile for:	jam
# Date created:		10 July 1998
# Whom:			Jeffrey Hsu <hsu@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	jam
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/pub/jam/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A build utility like make(1)

ONLY_FOR_ARCHS=	alpha i386 amd64

USE_ZIP=	yes
USE_REINPLACE=	yes
EXTRACT_BEFORE_ARGS=	-q -aa
NO_WRKSUBDIR=	yes

DOCSDIR=	${PREFIX}/share/doc/jam

post-extract:
	@${CHMOD} u+w ${WRKSRC}/Makefile

pre-patch:
	@${REINPLACE_CMD} -e 's|^CC|#CC|g ; \
		 s|^CFLAGS|#CFLAGS|g ; \
		 s|^	jam|	./jam|g' ${WRKSRC}/Makefile

do-install:
.if ${MACHINE_ARCH} == "alpha"
	${INSTALL_PROGRAM} ${WRKSRC}/bin.freebsdaxp/jam ${PREFIX}/bin
.else
	${INSTALL_PROGRAM} ${WRKSRC}/bin.freebsd/jam ${PREFIX}/bin
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
