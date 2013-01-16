# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	tpasm
PORTVERSION=	1.8
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ct0.com/pub/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-assembler for variety of microprocessors and controllers

LICENSE=	GPLv2

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

post-patch:
	@${REINPLACE_CMD} -e \
		's|-O2|| ; \
		 s|CFLAGS=|CFLAGS+=| ; \
		 s|$$(CC) -O|$$(CXX) $$(LDFLAGS)| ; \
		 s|-lstdc++||' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${PREFIX}/bin)
	@${MKDIR} ${PREFIX}/libdata/${PORTNAME}
	(cd ${WRKSRC}/include \
		&& ${INSTALL_DATA} * ${PREFIX}/libdata/${PORTNAME})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in CONVERSION_C166.TXT MANUAL.TXT README*.TXT
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/samples && ${INSTALL_DATA} * ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
