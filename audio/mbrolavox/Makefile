# Created by: trevor
# $FreeBSD$

PORTNAME=	mbrolavox
PORTVERSION=	3.0.1
CATEGORIES=	audio accessibility
DISTFILES=	#
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Voices for MBROLA voice synthesizer

USE_ZIP=	yes
NO_BUILD=	yes
RESTRICTED=	No commercial nor military use, no sale
WRKSRC=		${WRKDIR}/voices
PLIST=		${WRKDIR}/plist

VOICESCONF=	${.CURDIR}/voices.conf

.if !defined(OPTIONS)
OPTIONS!=	/usr/bin/awk -F'|' '{ print $$1 " \"" $$3 "\" " $$4 }' < ${VOICESCONF}
.endif

.include <bsd.port.pre.mk>

.if !defined(ALLOPTIONS)
ALLOPTIONS!=	${CUT} -f 1 -d '|' < ${VOICESCONF}
.endif

.for ii in ${ALLOPTIONS}
FILE_${ii}!=	${AWK} -F'|' '$$1 == "${ii}" { print $$2 }' < ${VOICESCONF}
.   if defined(WITH_${ii})
MASTER_SITES+=	http://www.tcts.fpms.ac.be/synthesis/mbrola/dba/${ii}/:${ii} \
		http://www.festvox.org/mbrola/dba/${ii}/:${ii} \
		http://mambo.ucsc.edu/psl/mbrola/dba/${ii}/:${ii} \
		ftp://ftp.loria.fr/pub/pc/mbrpsola/${ii}/:${ii} \
		ftp://tcts.fpms.ac.be/pub/mbrola/VOICES/${ii}/:${ii}
DISTFILES+=	${FILE_${ii}}:${ii}
FILEDIRS+=	${ii}
MYFILES+=	${FILE_${ii}}
.   endif
.endfor

do-extract:
	@${MKDIR} ${WRKSRC}
.for ii in ${MYFILES}
	@${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${ii} -d ${WRKSRC}
.endfor

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC}; \
	for ii in `${FIND} * \! -type d | ${SORT}`; do \
		${ECHO_CMD} %%DATADIR%%/$${ii} >> ${PLIST}; \
	done ; \
	for ii in `${FIND} -d * -type d`; do \
		${ECHO_CMD} @dirrm %%DATADIR%%/$${ii} >> ${PLIST}; \
	done
	@${ECHO_CMD} @dirrm %%DATADIR%% >> ${PLIST}

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC} && ${FIND} * | ${CPIO} -dlmp ${DATADIR}
	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} ${BINMODE}

.include <bsd.port.post.mk>
