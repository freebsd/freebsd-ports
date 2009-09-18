# New ports collection makefile for:	XMill
# Date created:				09 May 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	xmill
DISTVERSION=	0.8
CATEGORIES=	archivers
MASTER_SITES=	SF

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	An efficient compressor for XML

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile

USE_ZIP=	yes
USE_DOS2UNIX=	${MAKEFILE} XMill/BZlib.cpp

PLIST_FILES=	bin/xcmill bin/xdemill bin/xmilltest bin/xmillexample \
		bin/xmillinspect bin/ppmzip

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

post-patch:
# Allow to build with modern GCC
	@${REINPLACE_CMD} -e 's,friend,& class,' ${WRKSRC}/XMill/*.?pp \
		${WRKSRC}/xmillinspect/xmillinspect.h

do-install:
.for p in ${PLIST_FILES:T}
	${INSTALL_PROGRAM} ${WRKSRC}/unix/${p} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation/* ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
