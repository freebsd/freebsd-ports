# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bonnie++
PORTVERSION=	1.97
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.coker.com.au/bonnie++/experimental/
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Performance Test of Filesystem I/O

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GCC=	yes

USES=	shebangfix
SHEBANG_FILES=	bon_csv2txt.in

WRKSRC=	${WRKDIR}/${PORTNAME}-1.97.1

PORTDOCS=	readme.html

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
		's|/usr/share/|${PREFIX}/share/|g' ${WRKSRC}/bonnie++.8
	@${REINPLACE_CMD} \
		's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.html ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
