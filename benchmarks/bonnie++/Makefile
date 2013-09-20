# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bonnie++
PORTVERSION=	1.97
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.coker.com.au/bonnie++/experimental/
EXTRACT_SUFX=	.tgz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Performance Test of Filesystem I/O

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}-1.97.1

MAN1=	bon_csv2html.1 bon_csv2txt.1 generate_randfile.1
MAN8=	bonnie++.8 getc_putc.8 zcav.8

PORTDOCS=	readme.html

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
		's|/usr/share/|${PREFIX}/share/|g' ${WRKSRC}/bonnie++.8
	@${REINPLACE_CMD} \
		's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
