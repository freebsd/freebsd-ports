# New ports collection makefile for:	edict
# Version required:	19981007
# Date created:		18 August 1997
# Whom:			Jonathan Hanna
#
# $Id: Makefile,v 1.2 1998/10/10 04:34:51 steve Exp $
#

DISTNAME=	edict-19981007
PKGNAME=	ja-edict-19981007
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.cc.monash.edu.au/pub/nihongo/
MASTER_SITES+=	ftp://ftp.cdrom.com/pub/japanese/monash/
MASTER_SITES+=	ftp://ftp.sedl.org/pub/mirrors/nihongo/
MASTER_SITES+=	ftp://ftp.u-aizu.ac.jp/pub/SciEng/nihongo/ftp.cc.monash.edu.au/
EXTRACT_SUFX=
DISTFILES=	${DICTFILES} ${SRCFILES} ${DOCFILES}

MAINTAINER=	jhanna@home.com

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

DIST_SUBDIR=	edict

DOCFILES=	edict.doc
DOCFILES+=	edicth.doc
DOCFILES+=	enamdict.doc
DOCFILES+=	compdic.doc
DOCFILES+=	jddict.doc
DOCFILES+=	kanjidic.doc
DOCFILES+=	lifscdic.doc
DOCFILES+=	lawgldoc.new
DOCFILES+=	geodic.doc
DOCFILES+=	aviation.doc
DOCFILES+=	findic.doc
DOCFILES+=	mktdic.doc
DOCFILES+=	compverb.doc
DOCFILES+=	4jwords.doc

DICTFILES=	edict.gz
DICTFILES+=	edicth
DICTFILES+=	enamdict.gz
DICTFILES+=	compdic.gz
DICTFILES+=	jddict.v02.gz
DICTFILES+=	lifscdic.Z
DICTFILES+=	kanjidic.gz
DICTFILES+=	lawgledt.zip
DICTFILES+=	geodic.gz
DICTFILES+=	pandpdic.zip
DICTFILES+=	aviation.zip
DICTFILES+=	findic.zip
DICTFILES+=	mktdic.zip
DICTFILES+=	compverb.gz
DICTFILES+=	4jwords.gz

SRCFILES=	xjdic23.tgz

DOCFILES=	edict.doc
DOCFILES+=	edicth.doc
DOCFILES+=	enamdict.doc
DOCFILES+=	compdic.doc
DOCFILES+=	jddict.doc
DOCFILES+=	kanjidic.doc
DOCFILES+=	lifscdic.doc
DOCFILES+=	lawgldoc.new
DOCFILES+=	geodic.doc
DOCFILES+=	aviation.doc
DOCFILES+=	findic.doc
DOCFILES+=	mktdic.doc
DOCFILES+=	compverb.doc
DOCFILES+=	4jwords.doc

#
# These change too often and are not made into executables.
#
IGNOREFILES=	$(DICTFILES) $(DOCFILES)

BINFILES=	exjdxgen
BINFILES+=	xjdic_cl
BINFILES+=	xjdic_sa
BINFILES+=	xjdserver
BINFILES+=	xjdxgen

# Where to install the data files
DATADIR=	${PREFIX}/share/dict/edict
DOCDIR=		${PREFIX}/share/doc/xjdic
MAN1=		xjdic.1

NO_WRKSUBDIR=	yes

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@for file in ${SRCFILES}; do \
		if ! (cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS});\
		then \
			exit 1; \
		fi \
	done

do-install:
	@for file in ${BINFILES}; do \
		if ! ${INSTALL_PROGRAM} ${WRKDIR}/$$file ${PREFIX}/bin ;\
		then \
			exit 1; \
		fi \
	done
	@if [ ! -d ${DATADIR} ] ; \
	then \
		${MKDIR} ${DATADIR} ; \
	fi
	@for file in ${DICTFILES}; do \
		case $$file in \
		*.gz) \
			instfile=`basename $$file .gz` ; \
			if ${GZIP_CMD} -cd ${_DISTDIR}/$$file > ${DATADIR}/$$instfile ; \
			then \
				true ; \
			else \
				exit 1; \
			fi \
			;; \
		*.Z) \
			instfile=`basename $$file .Z` ; \
			if ${GZIP_CMD} -cd ${_DISTDIR}/$$file > ${DATADIR}/$$instfile ; \
			then \
				true ; \
			else \
				exit 1; \
			fi \
			;; \
		*.zip) \
			instfile=`basename $$file .zip` ; \
			if unzip -o ${_DISTDIR}/$$file $$instfile -d ${DATADIR} ; \
			then \
				true ; \
			else \
				exit 1; \
			fi \
			;; \
		*) \
			instfile=`basename $$file` ; \
			${CP} ${_DISTDIR}/$$file ${DATADIR} ; \
			;; \
		esac ; \
		( \
			${ECHO} cd ${DATADIR} ; \
			cd ${DATADIR} ; \
			${ECHO} ${PREFIX}/bin/xjdxgen $$instfile ; \
			${PREFIX}/bin/xjdxgen $$instfile ; \
			chown ${SHAREOWN}.${SHAREGRP} $$instfile $$instfile.xjdx; \
			chmod ${SHAREMODE} $$instfile $$instfile.xjdx ; \
		) ; \
	done
	${RM} -f ${PREFIX}/bin/xjdic
	ln -s ${PREFIX}/bin/xjdic_sa ${PREFIX}/bin/xjdic
	${INSTALL_DATA} ${WRKDIR}/radicals.tm ${DATADIR} ;
	${INSTALL_DATA} ${WRKDIR}/radkfile ${DATADIR} ;
	${INSTALL_DATA} ${WRKDIR}/kanjstroke ${DATADIR} ;
	${INSTALL_DATA} ${WRKDIR}/romkana.cnv ${DATADIR} ;
	${INSTALL_DATA} ${WRKDIR}/vconj ${DATADIR} ;
	#
	# Only 9 dictionaries can be enabled
	#
	@${ECHO} dicdir ${DATADIR} > ${DATADIR}/.xjdicrc
	@${ECHO} dicfile edict >> ${DATADIR}/.xjdicrc
	@${ECHO} dicfile enamdict >> ${DATADIR}/.xjdicrc
	@${ECHO} dicfile compdic >> ${DATADIR}/.xjdicrc
	@${ECHO} dicfile lifscdic >> ${DATADIR}/.xjdicrc
	# @${ECHO} dicfile jddict.v02 >> ${DATADIR}/.xjdicrc
	# @${ECHO} dicfile lawgledt >> ${DATADIR}/.xjdicrc
	@${ECHO} dicfile geodic >> ${DATADIR}/.xjdicrc
	@${ECHO} dicfile pandpdic >> ${DATADIR}/.xjdicrc
	@${ECHO} dicfile aviation >> ${DATADIR}/.xjdicrc
	# @${ECHO} dicfile findic >> ${DATADIR}/.xjdicrc
	# @${ECHO} dicfile mktdic >> ${DATADIR}/.xjdicrc
	@${ECHO} dicfile compverb >> ${DATADIR}/.xjdicrc
	@${ECHO} dicfile 4jwords >> ${DATADIR}/.xjdicrc
	@chown ${SHAREOWN}.${SHAREGRP} ${DATADIR}/.xjdicrc
	@chmod ${SHAREMODE} ${DATADIR}/.xjdicrc
	${INSTALL_MAN} ${WRKSRC}/xjdic.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@if [ ! -d ${DOCDIR} ] ; \
	then \
		${MKDIR} ${DOCDIR} ; \
	fi
	${INSTALL_MAN} ${WRKSRC}/xjdic23.inf ${DOCDIR}
	@for docfile in ${DOCFILES} ; do \
		${ECHO} InstalLing  ${DOCDIR}/$$docfile ; \
		${INSTALL_MAN}  ${_DISTDIR}/$$docfile ${DOCDIR} ; \
	done
.endif

.include <bsd.port.mk>
