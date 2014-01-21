# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	liblouis
PORTVERSION=	1.5.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Open-source Braille Translator And Back-translator

OPTIONS_DEFINE=	DOCS

USES=		gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

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
	${INSTALL_DATA} ${WRKSRC}/tables/*.utb2 ${STAGEDIR}${DATADIR}/tables/
	${INSTALL_DATA} ${WRKSRC}/tables/*.dis ${STAGEDIR}${DATADIR}/tables/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in liblouis-guide.html liblouis-guide.txt
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
