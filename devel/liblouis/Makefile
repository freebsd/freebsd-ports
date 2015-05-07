# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	liblouis
PORTVERSION=	2.5.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.liblouis.org/downloads/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open-source Braille Translator And Back-translator

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INFO=		liblouis

post-extract:
	@${REINPLACE_CMD} -e \
		's#@libdir@#${PREFIX}/libdata#g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's#tables doc tests python#tests python#g' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/tables
	${INSTALL_DATA} ${WRKSRC}/tables/*.dic ${STAGEDIR}${DATADIR}/tables/
	${INSTALL_DATA} ${WRKSRC}/tables/*.ctb ${STAGEDIR}${DATADIR}/tables/
	${INSTALL_DATA} ${WRKSRC}/tables/*.utb ${STAGEDIR}${DATADIR}/tables/
	${INSTALL_DATA} ${WRKSRC}/tables/*.cti ${STAGEDIR}${DATADIR}/tables/
	${INSTALL_DATA} ${WRKSRC}/tables/*.dis ${STAGEDIR}${DATADIR}/tables/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in liblouis.html liblouis.txt
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
