# New ports collection makefile for:	cnprint
# Date created:		29 Jan 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=		cnprint
PORTVERSION=		3.30b
CATEGORIES=		chinese print
MASTER_SITES=		ftp://freebsd.sinica.edu.tw/pub/statue/cnprint/ \
			http://nba184.med.uth.tmc.edu:3006/~cai/software/cnp/ \
			http://nba184.med.uth.tmc.edu:3006/~cai/software/cnp/metrics/ \
			http://nba184.med.uth.tmc.edu:3006/~cai/software/cnp/fonts/ \
			ftp://ftp.csc.cuhk.edu.hk/pub/chinese/ifcss/software/fonts/misc/ \
			http://www.ibiblio.org/pub/packages/ccic/software/fonts/big5/hbf/
DISTFILES=		cnprint330b.c \
			cnprint330b.readme \
			ttfb330b.c \
			cnprint330b.hlp \
			cnprint33.cmd \
			helvet.dat  \
			mssong.ttf.gz mssong.htf \
			mshei.ttf.gz mshei.htf \
			cc48s.hbf cc48.sym.gz \
			cc48s.1.gz \
			cc48s.2.gz \
			hbf.tar.gz \
			ntu_kai48.hbf ntu_kai48.bin.gz

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Convert Chinese-Big5/GB encoded files to Postscript, using TTF fonts

DIST_SUBDIR=		${PORTNAME}-${PORTVERSION}

do-extract:
	${MKDIR} ${WRKSRC}
.for i in ${DISTFILES}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${i} ${WRKSRC}
.endfor
	cd ${WRKSRC} ; \
	${TAR} pzvxf hbf.tar.gz ; ${MV} hbf/* . ; \
	${RM} -fr hbf ; \
	${GUNZIP_CMD} *.gz || ${TRUE}

do-build:
	cd ${WRKSRC} ; \
	${CC} cnprint330b.c ttfb330b.c -o cnprint -DPREFIX=\"${PREFIX}\" ; \
	${SED} \
		-e 's/\(DEFAULT_JIS_FONT\):.*$$/\1: kanji48.hbf/' \
		-e 's/\(DEFAULT_BIG5FONT\):.*$$/\1: ntu_kai48.hbf/' \
		-e 's/\(DEFAULT_ENCODING\):.*$$/\1: BIG5/' \
		>cnprint.cmd <cnprint33.cmd

do-install:
	${MKDIR} ${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/cnprint.cmd ${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.sym ${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.htf ${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.hbf ${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.bin ${PREFIX}/share/cnprint
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${PREFIX}/share/cnprint
	${INSTALL_PROGRAM} ${WRKSRC}/cnprint ${PREFIX}/bin

.include <bsd.port.mk>
