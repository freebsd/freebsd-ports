# New ports collection makefile for:		mbrolavox
# Date created:					2003-10-05
# Whom:						trevor
#
# $FreeBSD$
#

PORTNAME=	mbrolavox
PORTVERSION=	3.0.1
CATEGORIES=	audio accessibility
MASTER_SITES=
DIST_SUBDIR=	mbrolavox

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Voices for MBROLA voice synthesizer

.include <bsd.port.pre.mk>

NO_BUILD=	yes
RESTRICTED=	"no commercial nor military use, no sale"
USE_ZIP=	yes
PLIST=		${WRKDIR}/plist
WRKSRC=		${WRKDIR}/voices

BROKEN=		"Does not fetch"
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2004-06-18

.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

pre-everything::
	${MKDIR} ${WRKSRC}
.if !exists(${WRKDIRPREFIX}${.CURDIR}/work/voices.conf)
.if !defined(BATCH)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
.endif
.endif
DISTFILES?=	us1-980512.zip

.if exists(${WRKDIRPREFIX}${.CURDIR}/work/voices.conf)
DISTFILES!=${CAT} ${WRKDIRPREFIX}${.CURDIR}/work/voices.conf
PATCHDIRS!=${CAT} ${WRKDIRPREFIX}${.CURDIR}/work/fetchdirs.conf
.endif
.for ii in ${PATCHDIRS}
MASTER_SITES+=	http://www.festvox.org/mbrola/dba/${ii}/ \
	http://mambo.ucsc.edu/psl/mbrola/dba/${ii}/ \
	ftp://ftp.loria.fr/pub/pc/mbrpsola/${ii}/ \
	ftp://tcts.fpms.ac.be/pub/mbrola/VOICES/${ii}/
.endfor

do-extract:
.for ii in ${DISTFILES}
	@unzip -qo ${DISTDIR}/${DIST_SUBDIR}/${ii} -d ${WRKSRC}
.endfor

do-patch:
	@${DO_NADA}

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
