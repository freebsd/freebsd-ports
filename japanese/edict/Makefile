PORTNAME=	edict
PORTVERSION=	19990714
PORTREVISION=	6
CATEGORIES=	japanese
MASTER_SITES=	\
		http://japanology.arts.kuleuven.ac.be/mirrors/monash/ \
		http://ftp.edrdg.org/pub/Nihongo/
DISTFILES=	${DICTFILES} ${SRCFILES} ${DOCFILES}
DIST_SUBDIR=	edict
EXTRACT_ONLY=	${SRCFILES}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese-English dictionaries with access and maintenance utilities
WWW=		http://ftp.monash.edu.au/pub/nihongo/00INDEX.html

# Fix build with clang11
CFLAGS+=	-fcommon

DICTFILES=	edict.gz edicth enamdict.gz compdic.gz \
		j_places.gz ediclsd3.zip \
		kanjidic.gz kanjd212.gz lawgledt.zip \
		lingdic.zip geodic.gz pandpdic.zip \
		aviation.zip findic.zip mktdic.zip \
		4jword3_edict.zip concrete.zip

SRCFILES=	xjdic23.tgz

DOCFILES=	edict_doc.html edicth.doc \
		enamdict_doc.txt enamdict_doc.html \
		j_places.inf kanjidic.doc kanjd212.doc ediclsd3.rme \
		lawgldoc.new lingdic.txt geodic.doc aviation.txt \
		findic.doc mktdic.doc 4jword3_inf.txt \
		concrete.doc

BINFILES=	exjdxgen xjdic_cl xjdic_sa xjdserver xjdxgen

# Where to install the data files
DATADIR=	${PREFIX}/share/dict/edict
DOCSDIR=	${PREFIX}/share/doc/xjdic

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${GREP} -l '^main' ${WRKSRC}/*.c | ${XARGS} ${REINPLACE_CMD} \
		-e '/argv/s/unsigned//'

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${BINFILES} ${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} ${_DISTDIR}/edicth ${STAGEDIR}${DATADIR}
.for f in edict enamdict compdic j_places kanjidic kanjd212 geodic
	${GZIP_CMD} -cd ${_DISTDIR}/${f}.gz > ${STAGEDIR}${DATADIR}/${f}
.endfor
.for f in ediclsd3 lawgledt lingdic pandpdic aviation findic mktdic \
	4jword3_edict concrete
	cd ${STAGEDIR}${DATADIR} && \
		${TAR} -xf ${_DISTDIR}/${f}.zip ${f:S|edict|edict.euc|}
.endfor
.for dict in ${DICTFILES:S|_edict|_edict.euc|}
	(cd ${STAGEDIR}${DATADIR} && ${STAGEDIR}${PREFIX}/bin/xjdxgen ${dict:R})
	(cd ${STAGEDIR}${DATADIR} && ${CHMOD} ${SHAREMODE} \
		${dict:R} ${dict:R}.xjdx)
.endfor
	${RM} ${STAGEDIR}${PREFIX}/bin/xjdic
	(cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s xjdic_sa xjdic)
	(cd ${WRKSRC} && ${INSTALL_DATA} radicals.tm radkfile kanjstroke \
		romkana.cnv vconj ${STAGEDIR}${DATADIR})
	#
	# Only 9 dictionaries can be enabled
	#
	@${ECHO_CMD} dicdir ${DATADIR} > ${STAGEDIR}${DATADIR}/.xjdicrc
	@${ECHO_CMD} dicfile edict >> ${STAGEDIR}${DATADIR}/.xjdicrc
	@${ECHO_CMD} dicfile enamdict >> ${STAGEDIR}${DATADIR}/.xjdicrc
	@${ECHO_CMD} dicfile compdic >> ${STAGEDIR}${DATADIR}/.xjdicrc
	@${ECHO_CMD} dicfile ediclsd3 >> ${STAGEDIR}${DATADIR}/.xjdicrc
	@${ECHO_CMD} dicfile j_places >> ${STAGEDIR}${DATADIR}/.xjdicrc
	# @${ECHO_CMD} dicfile lawgledt >> ${DATADIR}/.xjdicrc
	@${ECHO_CMD} dicfile geodic >> ${STAGEDIR}${DATADIR}/.xjdicrc
	# @${ECHO_CMD} dicfile pandpdic >> ${DATADIR}/.xjdicrc
	@${ECHO_CMD} dicfile aviation >> ${STAGEDIR}${DATADIR}/.xjdicrc
	# @${ECHO_CMD} dicfile findic >> ${DATADIR}/.xjdicrc
	# @${ECHO_CMD} dicfile mktdic >> ${DATADIR}/.xjdicrc
	@${ECHO_CMD} dicfile 4jword3_edict.euc >> ${STAGEDIR}${DATADIR}/.xjdicrc
	# @${ECHO_CMD} dicfile concrete.doc >> ${DATADIR}/.xjdicrc
	# @${ECHO_CMD} dicfile lingdic >> ${DATADIR}/.xjdicrc
	@${CHMOD} ${SHAREMODE} ${STAGEDIR}${DATADIR}/.xjdicrc
	${INSTALL_MAN} ${WRKSRC}/xjdic.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/xjdic23.inf ${STAGEDIR}${DOCSDIR}
	(cd ${_DISTDIR} && ${INSTALL_DATA} ${DOCFILES} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
