# New ports collection makefile for:	liblouis
# Date created:				06 Feb 2009
# Whom:					Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	liblouis
PORTVERSION=	1.5.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	wenheping@gmail.com
COMMENT=	An Open-source Braille Translator And Back-translator

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

post-extract:
	@${REINPLACE_CMD} -e \
		's#@libdir@#${PREFIX}/libdata#g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's#tables doc tests python#tests python#g' ${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${DATADIR}/tables
	${INSTALL_DATA} ${WRKSRC}/tables/*.dic ${DATADIR}/tables/
	${INSTALL_DATA} ${WRKSRC}/tables/*.ctb ${DATADIR}/tables/
	${INSTALL_DATA} ${WRKSRC}/tables/*.utb ${DATADIR}/tables/
	${INSTALL_DATA} ${WRKSRC}/tables/*.cti ${DATADIR}/tables/
	${INSTALL_DATA} ${WRKSRC}/tables/*.utb2 ${DATADIR}/tables/
	${INSTALL_DATA} ${WRKSRC}/tables/*.dis ${DATADIR}/tables/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in liblouis-guide.html liblouis-guide.txt
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
