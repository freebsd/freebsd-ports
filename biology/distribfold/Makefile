# New ports collection makefile for:	folding@home client
# Date created:		Sun Sep 29 19:48:01 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	distribfold
PORTVERSION=	0.1.${RELEASE_DATE}
CATEGORIES=	biology net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	lioux
DISTNAME=	distribfold-current-FreeBSD-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	distributedfolding.org distributed protein folding project

ONLY_FOR_ARCHS=	i386
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_SIZE=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/distribfold

# files to install
SCRIPT_FILES=	distrib-update foldit
PROGRAM_FILES=	foldtrajlite
# installation dir
DESTINATION_DIR=	${PREFIX}/distribfold

# default users
DNETFOLD_USER=dnetfold
DNETFOLD_GROUP=dnetfold

# default number of processors
WITH_NCPU?=	1

RELEASE_DATE=	20040613

post-patch:
	@${REINPLACE_CMD} -E -e 's|%%DESTINATION_DIR%%|${DESTINATION_DIR}/cpu0|' \
		${WRKSRC}/foldit

pre-install:
# create users
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

do-install:
# remove any patch scrap files
.for ext in bak orig
	@${RM} -f ${WRKSRC}/*.${ext}
.endfor
# strip binaries
.for file in ${PROGRAM_FILES}
	@${STRIP_CMD} ${WRKSRC}/${file}
.endfor
# install startup script
	@${INSTALL_SCRIPT} ${WRKDIR}/distribfold.sh ${PREFIX}/etc/rc.d
# for every cpu directory
	@ncpu=`${CAT} ${WRKDIR}/ncpu` ; \
	for dir in `${FILESDIR}/number_of_dirs.sh $${ncpu}` ; do \
		DESTINATION_DIR=${DESTINATION_DIR}/cpu$${dir} ; \
		${MKDIR} $${DESTINATION_DIR} ; \
		${INSTALL_DATA} ${WRKSRC}/* $${DESTINATION_DIR} ; \
		${CHGRP} -R ${DNETFOLD_GROUP} $${DESTINATION_DIR} ; \
		${CHMOD} g+w $${DESTINATION_DIR} ; \
		${CHOWN} ${DNETFOLD_USER} $${DESTINATION_DIR}/* ; \
		${CHMOD} u+w $${DESTINATION_DIR}/* ; \
		for file in ${PROGRAM_FILES} ${SCRIPT_FILES} ; do \
			${CHMOD} 0755 $${DESTINATION_DIR}/$${file} ; \
		done ; \
	done
# display package message
	@${CAT} ${PKGMESSAGE}

post-install: cook-install-plist fix-startup-scripts

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c_r.4:${PORTSDIR}/misc/compat4x
.endif

pre-everything::
.if ${WITH_NCPU} < 1
	@${ECHO_MSG} "===> Number of processors HAS to be at least 1"
	@${ECHO_MSG} "===> (${WITH_NCPU}) IS NOT"
	@${FALSE}
.endif
	@${ECHO_MSG} "=======> ATTENTION <======="
	@${ECHO_MSG} "===> If you want to have multiple copies of this program"
	@${ECHO_MSG} "===> running in order to make better use of your SMP"
	@${ECHO_MSG} "===> system, set WITH_CPU to the number of cpus"
	@${ECHO_MSG} "===> available in your system"
	@${ECHO_MSG} "===> For example, 2 cpus. \"make WITH_CPU=2\""
	@${ECHO_MSG} "===> Do not use this variable if you do not have a SMP"
	@${ECHO_MSG} "===> system. There is no advantage otherwise."

do-configure:
# prepare startup script
	@${SED} -e 's|%%DNETFOLD_USER%%|${DNETFOLD_USER}|' \
		-e 's|%%DESTINATION_DIR%%|${DESTINATION_DIR}|' \
		-e 's|%%NCPU%%|${WITH_NCPU}|' \
		${FILESDIR}/distribfold.sh > ${WRKDIR}/distribfold.sh
# record number of cpus
	@${ECHO} ${WITH_NCPU} > ${WRKDIR}/ncpu

cook-install-plist: generate-plist
.if ${WITH_NCPU} > 1
	@${GREP} cpu0 ${TMPPLIST} > ${WRKDIR}/plist
	@${TAIL} -n 2 ${TMPPLIST} > ${WRKDIR}/plist.end
	@${CP} /dev/null ${WRKDIR}/plistN
# for every cpu directory
	@ncpu=`${CAT} ${WRKDIR}/ncpu` ; \
	for dir in `${FILESDIR}/number_of_dirs.sh $${ncpu}` ; do \
		${SED} -e "s|cpu0|cpu$${dir}|" ${WRKDIR}/plist >> ${WRKDIR}/plistN ; \
	done
	@${CP} /dev/null ${TMPPLIST}
.for file in plistN plist.end
	@${CAT} ${WRKDIR}/${file} >> ${TMPPLIST}
.endfor
.endif

fix-startup-scripts:
.if ${WITH_NCPU} > 1
# for every cpu directory
	@ncpu=`${CAT} ${WRKDIR}/ncpu` ; \
	for dir in `${FILESDIR}/number_of_dirs.sh $${ncpu}` ; do \
		${REINPLACE_CMD} -e "s|cpu0|cpu$${dir}|" \
			${DESTINATION_DIR}/cpu$${dir}/foldit ; \
		${RM} -f ${DESTINATION_DIR}/cpu$${dir}/foldit.bak ; \
	done
.endif

.include <bsd.port.post.mk>
