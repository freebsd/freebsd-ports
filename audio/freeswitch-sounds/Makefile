# Ports collection makefile for: freeswitch-sounds
# Date created: May 11, 2010
# Whom: Eric F Crist <ecrist@secure-computing.net>
#
# $FreeBSD$
#

PORTNAME=	freeswitch
DISTVERSION=	1.0.18
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://files.freeswitch.org/
PKGNAMESUFFIX=	-sounds
DIST_SUBDIR=	freeswitch-sounds

MAINTAINER=	r.neese@gmail.com
COMMENT=	FreeSwitch Sounds (All Bitrates)

PLIST=		${WRKDIR}/plist
NO_WRKSUBDIR=	yes
SHAREOWN=	${PORTNAME}
SHAREGRP=	${SHAREOWN}
USERS=		${PORTNAME}
GROUPS=		${USERS}
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

OPTIONS=	DOWNLOAD	"Don't resample, download all." off \
		8K		"Compile sounds for 8K" on \
		16K		"Compile sounds for 16K" on \
		32K		"Compile sounds for 32K" on \
		48K		"Compile sounds for 48K" on \
		ENGLISH		"Compile US English Language Sounds" on \
		FRENCH		"Compile French Canadian Language Sounds" off \
		RUSSIAN		"Compile Russian Language Sounds" off
		
.include <bsd.port.options.mk>

.if ! defined(WITH_DOWNLOAD)
BUILD_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.endif

.if defined(WITH_8K)
BITRATES+=	8000
.endif
.if defined(WITH_16K)
BITRATES+=	16000
.endif
.if defined(WITH_32K)
BITRATES+=	32000
.endif
.if defined(WITH_48K)
BITRATES+=	48000
.endif

.if defined(WITH_ENGLISH)
.if defined(WITH_DOWNLOAD)
.for rate in ${BITRATES}
DISTFILES+=	${PORTNAME}${PKGNAMESUFFIX}-en-us-callie-${rate}-${DISTVERSION}${EXTRACT_SUFX}
.endfor
.else
DISTFILES+=	${PORTNAME}${PKGNAMESUFFIX}-en-us-callie-48000-${DISTVERSION}${EXTRACT_SUFX}
.endif
.endif
.if defined(WITH_FRENCH)
.if defined(WITH_DOWNLOAD)
.for rate in ${BITRATES}
DISTFILES+=	${PORTNAME}${PKGNAMESUFFIX}-fr-ca-june-${rate}-1.0.14${EXTRACT_SUFX}
.endfor
.else
DISTFILES+=     ${PORTNAME}${PKGNAMESUFFIX}-fr-ca-june-48000-1.0.14${EXTRACT_SUFX}
.endif
.endif
.if defined(WITH_RUSSIAN)
.if defined(WITH_DOWNLOAD)
.for rate in ${BITRATES}
DISTFILES+=	${PORTNAME}${PKGNAMESUFFIX}-ru-RU-elena-${rate}-1.0.12${EXTRACT_SUFX}
.endfor
.else
DISTFILES+=	${PORTNAME}${PKGNAMESUFFIX}-ru-RU-elena-48000-1.0.12${EXTRACT_SUFX}
.endif
.endif

.if ! defined(WITH_ENGLISH) && ! defined(WITH_FRENCH) && ! defined(WITH_RUSSIAN)
BROKEN=	you must build with atleast English or French or Russian, 
.endif

.if ! defined(WITH_8K) && ! defined(WITH_16K) && ! defined(WITH_32K) && \
	! defined(WITH_48K)
BROKEN=	you must build with at least one of 8K, 16K, 32K, or 48K sounds
.endif

.if defined(FREESWITCH_VSCALE)
SCALE=${FREESWITCH_VSCALE}
.else
SCALE=0.2
.endif

do-build:
	@${ECHO_MSG} "===> Building for bitrates: ${BITRATES}"
	@${ECHO_MSG} "===> Download >>>${WITH_DOWNLOAD}<<<"
	@${ECHO_MSG} "===> Scaling audio to ${SCALE}"
	if [ "${WITH_ENGLISH}" != "" -a ! -e "${WRKDIR}/ENGLISH.done" ]; then \
		${ECHO_MSG} "====> English selected."; \
		for rate in ${BITRATES}; do \
			${ECHO_MSG} "WORKING on $${rate}!"; \
			for dir in `ls ${WRKSRC}/en/us/callie/`; do \
				${MKDIR} ${WRKDIR}/tmp/en/us/callie/$${dir}/$${rate}/; \
				for filename in `ls ${WRKSRC}/en/us/callie/$${dir}/48000`; do \
					echo "${DATADIR_REL}/sounds/en/us/callie/$${dir}/$${rate}/$${filename}" >> ${PLIST}; \
					if [ ! -e "${WRKDIR}/tmp/en/us/callie/$${dir}/$${rate}/$${filename}" ]; then \
						if [ "${WITH_DOWNLOAD}" = "true" ]; then \
							${ECHO} -n "."; \
							${MV} ${WRKSRC}/en/us/callie/$${dir}/$${rate}/$${filename} ${WRKDIR}/tmp/en/us/callie/$${dir}/$${rate}/$${filename} ; \
						else \
							${ECHO} -n "."; \
							${LOCALBASE}/bin/sox -v ${SCALE} "${WRKSRC}/en/us/callie/$${dir}/48000/$${filename}" -r $${rate} -c 1 "${WRKDIR}/tmp/en/us/callie/$${dir}/$${rate}/$${filename}"; \
						fi \
					fi \
				done; \
				${ECHO} ""; \
				echo "@rmdir share/${PORTNAME}/sounds/en/us/callie/$${dir}/$${rate}/" >> ${PLIST}; \
			done; \
		done; \
		${TOUCH} ${WRKDIR}/ENGLISH.done; \
	fi

	if [ "${WITH_FRENCH}" != "" -a ! -e "${WRKDIR}/FRENCH.done" ]; then \
		${ECHO_MSG} "====> French selected."; \
		for rate in ${BITRATES}; do \
			${ECHO_MSG} "WORKING on $${rate}!"; \
			 for dir in `ls ${WRKSRC}/fr/ca/june/`; do \
				${MKDIR} ${WRKDIR}/tmp/fr/ca/june/$${dir}/$${rate}/; \
					 for filename in `ls ${WRKSRC}/fr/ca/june/$${dir}/48000`; do \
					echo "${DATADIR_REL}/sounds/fr/ca/june/$${dir}/$${rate}/$${filename}" >> ${PLIST}; \
					if [ ! -e "${WRKDIR}/tmp/fr/ca/june/$${dir}/$${rate}/$${filename}" ]; then \
						if [ "${WITH_DOWNLOAD}" = "true" ]; then \
							${ECHO} -n "."; \
							${MV} ${WRKSRC}/fr/ca/june/$${dir}/$${rate}/$${filename} ${WRKDIR}/tmp/fr/ca/june/$${dir}/$${rate}/$${filename} ; \
						else \
							${ECHO} -n "."; \
							${LOCALBASE}/bin/sox -v ${SCALE} "${WRKSRC}/fr/ca/june/$${dir}/48000/$${filename}" -r $${rate} -c 1 "${WRKDIR}/tmp/fr/ca/june/$${dir}/$${rate}/$${filename}"; \
						fi \
					fi \
				done; \
				${ECHO} ""; \
				echo "@rmdir share/${PORTNAME}/sounds/fr/ca/june/$${dir}/$${rate}/" >> ${PLIST}; \
			done; \
		done; \
		${TOUCH} ${WRKDIR}/FRENCH.done; \
	fi

	if [ "${WITH_RUSSIAN}" != "" -a ! -e "${WRKDIR}/RUSSIAN.done" ]; then \
		${ECHO_MSG} "====> Russian selected."; \
		for rate in ${BITRATES}; do \
			${ECHO_MSG} "WORKING on $${rate}!"; \
			for dir in `ls ${WRKSRC}/ru/RU/elena/`; do \
				${MKDIR} ${WRKDIR}/tmp/ru/RU/elena/$${dir}/$${rate}/; \
				for filename in `ls ${WRKSRC}/ru/RU/elena/$${dir}/48000`; do \
					echo "share/${DATADIR_REL}/sounds/ru/RU/elena/$${dir}/$${rate}/$${filename}" >> ${PLIST}; \
					if [ ! -e "${WRKDIR}/tmp/ru/RU/elena/$${dir}/$${rate}/$${filename}" ]; then \
						if [ "${WITH_DOWNLOAD}" = "true" ]; then \
							${ECHO} -n "."; \
							${MV} ${WRKSRC}/ru/RU/elena/$${dir}/$${rate}/$${filename} ${WRKDIR}/tmp/ru/RU/elena/$${dir}/$${rate}/$${filename}; \
						else \
							${ECHO} -n "."; \
							${LOCALBASE}/bin/sox -v ${SCALE} "${WRKSRC}/ru/RU/elena/$${dir}/48000/$${filename}" -r $${rate} -c 1 "${WRKDIR}/tmp/ru/RU/elena/$${dir}/$${rate}/$${filename}"; \
						fi \
					fi \
				done; \
				${ECHO} ""; \
				echo "@dirrm share/${PORTNAME}/sounds/ru/RU/elena/$${dir}/$${rate}/" >> ${PLIST}; \
			done; \
		done; \
		${TOUCH} ${WRKDIR}/RUSSIAN.done; \
	fi

pre-install:
	@${RM} ${PLIST}
	@cd ${WRKDIR}/tmp && ${FIND} * ! -type d | ${SORT} >> ${PLIST}; \
	${ECHO_CMD} .${PORTNAME}${PKGNAMESUFFIX} >> ${PLIST}; \
	${REINPLACE_CMD} -e "s:^:${DATADIR_REL}/sounds/:" ${PLIST}; \
	${FIND} * -type d ! -empty | ${SORT} -r | ${SED} -e "s:^:@dirrm ${DATADIR_REL}/sounds/:" | ${GREP} / >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry ${DATADIR_REL}/sounds" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry ${DATADIR_REL}" >> ${PLIST}

do-install:
	@${ECHO_MSG} "Installing files..."
	${MKDIR} ${DATADIR}/sounds
	${TOUCH} ${DATADIR}/sounds/.freeswitch-sounds
	(cd ${WRKDIR}/tmp/ && ${COPYTREE_SHARE} \* ${DATADIR}/sounds/)

.include <bsd.port.mk>
