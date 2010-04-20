# New ports collection makefile for:	edict
# Date created:		18 August 1997
# Whom:			Jonathan Hanna
#
# $FreeBSD$
#

PORTNAME=	edict-utf-8
PORTVERSION=	20100420
CATEGORIES=	japanese
MASTER_SITES=	http://redundancy.redundancy.org/mirror/${PORTNAME}/
DISTFILES=	${DICTFILES}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Japanese-English edict UTF-8 dictionaries

EXTRACT_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_ICONV=	yes
ICONV?=		iconv
CONVERT_CMD=	${ICONV} -c -f EUC-JP -t UTF-8

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

PLIST_FILES=	${DICTFILES:S|^|%%DATADIR%%/|:S|.gz||:S|.zip||}
PLIST_DIRS=	%%DATADIR%%

# Where to install the data files
DATADIR=	${PREFIX}/share/dict/edict-utf-8

NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
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
	@if [ ! -d ${DATADIR} ] ; \
	then \
		${MKDIR} ${DATADIR} ; \
	fi
	@for file in `cat ${WRKSRC}/filelist`; do \
		${ECHO} "Installing $$file"; \
		${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE} \
		${WRKSRC}/$$file ${DATADIR}/$$file; \
	done

.include <bsd.port.post.mk>
