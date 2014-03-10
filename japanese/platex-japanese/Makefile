# Created by: Koji Yokota <yokota@res.otaru-uc.ac.jp>
# $FreeBSD$

PORTNAME=	japanese
PORTVERSION=	1.3
PORTREVISION=	5
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	language/japanese
PKGNAMEPREFIX=	platex-
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	latex

MAINTAINER=	yokota@res.otaru-uc.ac.jp
COMMENT=	pLaTeX package that literally provides Japanese option to babel

USE_TEX=	latex ptex
USES=		iconv:build zip

TEXMFDIR=	share/texmf
STYDIR=		tex/generic/babel
DOCSDIR=	doc/generic/babel/${PORTNAME}
INSFILE=	${PORTNAME}.ins
DTXFILE=	${PORTNAME}.dtx
LDFFILE=	${PORTNAME}.ldf
SAMPLEFILE=	sample.tex
PDFFILE=	sample.pdf
TEXTFILE=	README
ENCODING?=	EUC-JP
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

NO_STAGE=	yes
.SILENT::
pre-configure:
	@${ECHO_MSG}
	@${ECHO_MSG} Using ${ENCODING} to set locale of installing files.
	@${ECHO_MSG} To change it, set the $$\{ENCODING\} variable to a desirable iconv\'s locale.
	@${ECHO_MSG} See \'iconv -l\' for available values.
	@${ECHO_MSG}

post-configure:
	( cd ${WRKSRC} && ${MV} ${INSFILE} ${INSFILE:S/$/.orig/} && \
	   ${SED} -e 's/\(sample\.tex\)/j\1/g' ${INSFILE:S/$/.orig/} \
	   > ${INSFILE} && \
	   ${MV} ${DTXFILE} ${DTXFILE}.orig && \
	   ${ICONV_CMD} -f ISO-2022-JP -t ${ENCODING} ${DTXFILE}.orig > ${DTXFILE} )

do-build:
	( cd ${WRKSRC} && platex ${INSFILE} && \
	   ${MV} j${SAMPLEFILE} ${SAMPLEFILE})

do-install:
	( cd ${WRKSRC} && \
	   ${MKDIR} ${PREFIX}/${TEXMFDIR}/${STYDIR} && \
	   ${CP} -pv ${LDFFILE} ${PREFIX}/${TEXMFDIR}/${STYDIR} )
.if !defined(NOPORTDOCS)
	( cd ${WRKSRC} && \
	   ${MKDIR} ${PREFIX}/${TEXMFDIR}/${DOCSDIR} && \
	   for _FILE in ${PDFFILE} ${TEXTFILE} ${SAMPLEFILE} ; do \
	   ${CP} -pv $${_FILE} ${PREFIX}/${TEXMFDIR}/${DOCSDIR} ; done )
.endif

post-install:
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}

.include <bsd.port.mk>
