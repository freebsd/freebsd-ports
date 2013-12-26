# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	xmill
DISTVERSION=	0.8
CATEGORIES=	archivers
MASTER_SITES=	SF
EXTRACT_SUFX=	.zip

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Efficient compressor for XML

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile

USES=		dos2unix
DOS2UNIX_FILES=	${MAKEFILE} XMill/BZlib.cpp

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
	${INSTALL_PROGRAM} ${WRKSRC}/unix/${p} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation/* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
