# New ports collection makefile for:		mbrola
# Date created:					2003-10-04
# Whom:						trevor
#
# $FreeBSD$
#

PORTNAME=	mbrola
PORTVERSION=	3.0.1
CATEGORIES=	audio accessibility
MASTER_SITES=	ftp://tcts.fpms.ac.be/pub/mbrola/freebsd/
DISTNAME=	mbr301h
DIST_SUBDIR=	mbrola

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	MBROLA voice synthesizer

LIB_DEPENDS=	c.3:${PORTSDIR}/misc/compat3x

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
RESTRICTED=	"for non-commercial, non-military applications only"
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/mbr301h
PLIST=		${WRKDIR}/plist

.include <bsd.port.pre.mk>

.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

pre-everything::
	${MKDIR} ${WRKDIR}
.if !exists(${WRKDIRPREFIX}${.CURDIR}/work/voices.conf)
.if !defined(BATCH)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
.endif
.endif
PATCHILES?=	us1.zip

.if exists(${WRKDIRPREFIX}${.CURDIR}/work/voices.conf)
PATCHFILES!=${CAT} ${WRKDIRPREFIX}${.CURDIR}/work/voices.conf
PATCHDIRS!=${CAT} ${WRKDIRPREFIX}${.CURDIR}/work/fetchdirs.conf
.endif
.for ii in ${PATCHDIRS}
PATCH_SITES+=	http://www.festvox.org/mbrola/dba/${ii}/ \
	http://mambo.ucsc.edu/psl/mbrola/dba/${ii}/ \
	ftp://ftp.loria.fr/pub/pc/mbrpsola/${ii}/ \
	ftp://tcts.fpms.ac.be/pub/mbrola/VOICES/${ii}/
.endfor

do-extract:
.for ii in ${DISTNAME}.zip ${PATCHFILES}
	@unzip -qo ${DISTDIR}/${DIST_SUBDIR}/${ii} -d ${WRKSRC}
.endfor

do-patch:
	@${RM} -f ${WRKSRC}/mbrola-FreeBSD-i386-aout

pre-install:
	@${ECHO_CMD} bin/mbrola > ${PLIST}
	@cd ${WRKSRC}; \
	for ii in `${FIND} * \! -type d | sort`; do \
		${ECHO_CMD} share/mbrola/$${ii} >> ${PLIST}; \
	done ; \
	for ii in `${FIND} -d * -type d`; do \
		${ECHO_CMD} @dirrm share/mbrola/$${ii} >> ${PLIST}; \
	done
	@${ECHO_CMD} @dirrm share/mbrola >> ${PLIST}

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC} && ${FIND} * | cpio -dlmp ${DATADIR}
	@${CHMOD} +x ${DATADIR}/mbrola*
	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${LN} -s ${DATADIR}/mbrola-FreeBSD-i386-elf ${PREFIX}/bin/mbrola

.include <bsd.port.post.mk>
