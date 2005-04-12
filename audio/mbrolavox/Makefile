# New ports collection makefile for:		mbrolavox
# Date created:					2003-10-05
# Whom:						trevor
#
# $FreeBSD$
#

PORTNAME=	mbrolavox
PORTVERSION=	3.0.1
CATEGORIES=	audio accessibility

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Voices for MBROLA voice synthesizer

VOICESCONF=	${.CURDIR}/voices.conf

.if !defined(OPTIONS)
OPTIONS!=	/usr/bin/awk -F\| '{ print $$1 " \"" $$3 "\" " $$4 }' < ${VOICESCONF}
.endif
.if !defined(ALLOPTIONS)
ALLOPTIONS!=	/usr/bin/awk -F\| '{ print $$1 }' < ${VOICESCONF}
.for ii in ${ALLOPTIONS}
FILE_${ii}!=	/usr/bin/grep ^${ii} ${VOICESCONF} | /usr/bin/awk -F\| '{ print $$2 }'
.endfor
.endif

.include <bsd.port.pre.mk>

NO_BUILD=	yes
RESTRICTED=	"no commercial nor military use, no sale"
USE_ZIP=	yes
PLIST=		${WRKDIR}/plist
WRKSRC=		${WRKDIR}/voices

.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif
.if defined(PACKAGE_BUILDING)	# Ugly hack until OPTIONS and PACKAGE_BUILDING is fixed. Can be removed when ports/63682 has been commited.
WITH_us1?=	yes
.endif

.for ii in ${ALLOPTIONS}
. if defined(WITH_${ii})
FILEDIRS+=	${ii}
MYDISTFILES+=	${FILE_${ii}}:${ii}
MYFILES+=	${FILE_${ii}}
MYWITH+=	${ii}
. endif
.endfor
.if defined(MYDISTFILES)
DISTFILES=	${MYDISTFILES}
DIST_SUBDIR=	mbrolavox
.else
DISTFILES=	# none
.endif

.for ii in ${FILEDIRS}
MASTER_SITES+=	http://www.festvox.org/mbrola/dba/${ii}/:${ii} \
		http://mambo.ucsc.edu/psl/mbrola/dba/${ii}/:${ii} \
		ftp://ftp.loria.fr/pub/pc/mbrpsola/${ii}/:${ii} \
		ftp://tcts.fpms.ac.be/pub/mbrola/VOICES/${ii}/:${ii}
.endfor

do-build:
	@${DO_NADA}

do-extract:
	@${MKDIR} ${WRKSRC}
.for ii in ${MYFILES}
	@${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${ii} -d ${WRKSRC}
.endfor

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC}; \
	for ii in `${FIND} * \! -type d | ${SORT}`; do \
		${ECHO_CMD} share/mbrolavox/$${ii} >> ${PLIST}; \
	done ; \
	for ii in `${FIND} -d * -type d`; do \
		${ECHO_CMD} @dirrm share/mbrolavox/$${ii} >> ${PLIST}; \
	done
	@${ECHO_CMD} @dirrm share/mbrolavox >> ${PLIST}

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC} && ${FIND} * | ${CPIO} -dlmp ${DATADIR}
	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755

.include <bsd.port.post.mk>
