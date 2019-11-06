# Created by: Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	cnprint
PORTVERSION=	3.30b
PORTREVISION=	1
CATEGORIES=	chinese print
MASTER_SITES=	http://distfiles.cs.nctu.edu.tw/${PORTNAME}-${PORTVERSION}/
DISTFILES=	cnprint330b.c cnprint330b.readme ttfb330b.c cnprint330b.hlp \
		cnprint33.cmd helvet.dat  mssong.ttf.gz mssong.htf \
		mshei.ttf.gz mshei.htf cc48s.hbf cc48.sym.gz cc48s.1.gz \
		cc48s.2.gz hbf.tar.gz ntu_kai48.hbf ntu_kai48.bin.gz

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Print CJK text (or convert to PostScript)

BROKEN=		unfetchable

DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
FILES=		${WRKSRC}/*.sym ${WRKSRC}/*.htf ${WRKSRC}/*.hbf \
		${WRKSRC}/*.bin ${WRKSRC}/*.ttf

OPTIONS_DEFINE=	A4SIZE
OPTIONS_DEFAULT=	A4SIZE

A4SIZE_DESC=	Set A4 (not Letter) as a default paper size

do-extract:
	${MKDIR} ${WRKSRC}
.for i in ${DISTFILES}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${i} ${WRKSRC}
.endfor
	cd ${WRKSRC} ; \
	${TAR} pzvxf hbf.tar.gz ; ${MV} hbf/* . ; \
	${RM} -r hbf ; \
	${GUNZIP_CMD} *.gz || ${TRUE}

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local/src,${PREFIX}/share,' \
		${WRKSRC}/cnprint330b.c
	@${REINPLACE_CMD} -e 's/\(DEFAULT_JIS_FONT\):.*$$/\1: kanji48.hbf/; \
		s/\(DEFAULT_BIG5FONT\):.*$$/\1: ntu_kai48.hbf/; \
		s/\(DEFAULT_ENCODING\):.*$$/\1: BIG5/' ${WRKSRC}/cnprint33.cmd
post-patch-A4SIZE-on:
	@${REINPLACE_CMD} -e 's/\(DEFAULT_PAPERSIZE\):.*$$/\1: 8.27 11.69/' \
		${WRKSRC}/cnprint33.cmd

do-build:
	cd ${WRKSRC} ; \
	${CC} cnprint330b.c ttfb330b.c -o cnprint -DPREFIX=\"${PREFIX}\"

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/cnprint ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}33.cmd  ${STAGEDIR}${DATADIR}/${PORTNAME}.cmd
	${INSTALL_DATA} ${FILES} ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
