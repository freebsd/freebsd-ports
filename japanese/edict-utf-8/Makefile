# New ports collection makefile for:	edict
# Date created:		18 August 1997
# Whom:			Jonathan Hanna
#
# $FreeBSD$
#

PORTNAME=	edict-utf-8
PORTVERSION=	20050310
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.cc.monash.edu.au/pub/nihongo/ \
		http://japanology.arts.kuleuven.ac.be/mirrors/monash/ \
		ftp://ftp.nrc.ca/pub/packages/nihongo/ \
		http://www.bcit-broadcast.com/monash/ \
		ftp://ftp.mirrorservice.org/sites/ftp.cc.monash.edu.au/pub/nihongo/ \
		ftp://ftp.sedl.org/pub/mirrors/nihongo/ \
		ftp://ftp.net.usf.edu/pub/monash/ \
		ftp://ftp.u-aizu.ac.jp/pub/SciEng/nihongo/ftp.cc.monash.edu.au/ \
		ftp://ftp.funet.fi/pub/culture/japan/mirrors/monash/pub/nihongo/ \
		ftp://ftp.uni-duisburg.de/Mirrors/ftp.monash.edu.au/pub/nihongo/
DISTFILES=	${DICTFILES}
EXTRACT_ONLY=	# intentionally left blank

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Japanese-English edict UTF-8 dictionaries

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

BROKEN=		Install fails

USE_ICONV=	yes
ICONV?=		iconv
CONVERT_CMD=	${ICONV} -c -f EUC-JP -t UTF-8
NO_BUILD=	yes

DIST_SUBDIR=	edict

DICTFILES=	edict.gz edicth enamdict.gz compdic.gz \
		jddict.v02.gz j_places.gz ediclsd3.zip \
		kanjidic.gz kanjd212.gz lawgledt.zip \
		lingdic.zip geodic.gz pandpdic.zip \
		aviation.zip findic.zip mktdic.zip \
		compverb.gz 4jwords.gz concrete.zip

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

do-install:
	@if [ ! -d ${DATADIR} ] ; \
	then \
		${MKDIR} ${DATADIR} ; \
	fi
	@for file in ${DICTFILES}; do \
		case $$file in \
		*.gz) \
			instfile=`${BASENAME} $$file .gz` ; \
			if ${GZIP_CMD} -cd ${_DISTDIR}/$$file | ${CONVERT_CMD} \
				> ${DATADIR}/$$instfile ; \
			then \
				${TRUE} ; \
			else \
				exit 1; \
			fi \
			;; \
		*.zip) \
			instfile=`${BASENAME} $$file .zip` ; \
			if ${UNZIP_CMD} -c ${_DISTDIR}/$$file -x ${NODOCFILES} 2>/dev/null \
			| ${CONVERT_CMD} > ${DATADIR}/$$instfile ; \
			then \
				${TRUE} ; \
			else \
				exit 1; \
			fi \
			;; \
		*) \
			instfile=`${BASENAME} $$file` ; \
			${CONVERT_CMD} ${_DISTDIR}/$$file >${DATADIR}/$$instfile \
			;; \
		esac ; \
		( \
			cd ${DATADIR} ; \
			${CHOWN} ${SHAREOWN}:${SHAREGRP} $$instfile ; \
			${CHMOD} ${SHAREMODE} $$instfile  ; \
		) ; \
	done

.include <bsd.port.post.mk>
