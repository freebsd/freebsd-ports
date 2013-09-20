# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	xmill
DISTVERSION=	0.8
CATEGORIES=	archivers
MASTER_SITES=	SF

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Efficient compressor for XML

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile

NO_STAGE=	yes
USE_ZIP=	yes
USE_DOS2UNIX=	${MAKEFILE} XMill/BZlib.cpp

PLIST_FILES=	bin/xcmill bin/xdemill bin/xmilltest bin/xmillexample \
		bin/xmillinspect bin/ppmzip

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-patch:
# Allow to build with modern GCC
	@${REINPLACE_CMD} -e 's,friend,& class,' ${WRKSRC}/XMill/*.?pp \
		${WRKSRC}/xmillinspect/xmillinspect.h

do-install:
.for p in ${PLIST_FILES:T}
	${INSTALL_PROGRAM} ${WRKSRC}/unix/${p} ${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation/* ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
