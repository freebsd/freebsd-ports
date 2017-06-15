# Created by: Jonathan Hanna
# $FreeBSD$

PORTNAME=	edict-utf-8
PORTVERSION=	20100420
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://redundancy.redundancy.org/mirror/${PORTNAME}/
DISTFILES=	${DICTFILES}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese-English edict UTF-8 dictionaries

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip

USES=		iconv
CONVERT_CMD=	${ICONV_CMD} -c -f EUC-JP -t UTF-8
DIST_SUBDIR=	${PORTNAME}
DICTFILES=	edict.gz edicth compdic.gz jddict.v02.gz \
		j_places.gz ediclsd3.zip kanjidic.gz kanjd212.gz \
		lawgledt.zip lingdic.zip geodic.gz pandpdic.zip \
		aviation.zip findic.zip mktdic.zip compverb.gz \
		4jwords.gz concrete.zip enamdict.gz
NODOCFILES=	edict_doc.txt edict_doc.html edicth.doc \
		enamdict_doc.txt enamdict_doc.html jddict.doc \
		j_places.inf kanjidic.doc kanjd212.doc ediclsd3.rme \
		lawgldoc.new lingdic.txt geodic.doc aviation.txt \
		findic.doc mktdic.doc compverb.doc 4jwords.doc \
		concrete.doc ${DICTFILES:S/zip/jdx/}

# Where to install the data files
DATADIR=	${PREFIX}/share/dict/edict-utf-8
PLIST_SUB= 	OWNER="${SHAREOWN}" GROUP="${SHAREGRP}" MODE="${SHAREMODE}"

NO_WRKSUBDIR=	yes

do-extract:
	@${RM} -r ${WRKSRC}
	@${MKDIR} ${WRKSRC}
	@for file in ${DICTFILES}; do \
		${ECHO} "Extracting $$file"; \
		case $$file in \
		*.gz) \
			instfile=`${BASENAME} $$file .gz` ; \
			${GZIP_CMD} -dc ${_DISTDIR}/$$file > ${WRKSRC}/$$instfile.euc-jp \
			;; \
		*.zip) \
			instfile=`${BASENAME} $$file .zip` ; \
			${UNZIP_CMD} -qq -c ${_DISTDIR}/$$file -x ${NODOCFILES} 2>/dev/null \
			> ${WRKSRC}/$$instfile.euc-jp \
			;; \
		*) \
			instfile=$$file ; \
			${CP} ${_DISTDIR}/$$file ${WRKSRC}/$$file.euc-jp \
			;; \
		esac ; \
		${ECHO} $$instfile >> ${WRKSRC}/filelist; \
	done

do-build:
	@for file in `cat ${WRKSRC}/filelist`; do \
		${ECHO} "Converting $$file"; \
		${CONVERT_CMD} ${WRKSRC}/$$file.euc-jp > ${WRKSRC}/$$file; \
	done

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@for file in `cat ${WRKSRC}/filelist`; do \
		${ECHO} "Installing $$file"; \
		${INSTALL} ${WRKSRC}/$$file ${STAGEDIR}${DATADIR}/$$file; \
	done

.include <bsd.port.mk>
