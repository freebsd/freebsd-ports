# Ports collection makefile for: freeswitch-sounds
# Date created: May 11, 2010
# Whom: Eric F Crist <ecrist@secure-computing.net>
#
# $FreeBSD$
#

PORTNAME=	freeswitch-sounds
PORTVERSION=	1.0.16
CATEGORIES=	audio
MASTER_SITES=	http://files.freeswitch.org/
DIST_SUBDIR=	freeswitch-sounds

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	FreeSwitch Sounds (All Bitrates)

PLIST=		${WRKDIR}/plist
NO_WRKSUBDIR=	yes

BASE_PORTNAME=	freeswitch

OPTIONS=	DOWNLOAD     "Don't resample, download all." on \
		8K           "Compile sounds for 8K" on \
		16K          "Compile sounds for 16K" on \
		32K          "Compile sounds for 32K" on \
		48K          "Compile sounds for 48K" on \
		ENGLISH      "Compile English Language Sounds" on \
		RUSSIAN      "Compile Russian Language Sounds" off

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
DISTFILES+=	${PORTNAME}-en-us-callie-${rate}-${PORTVERSION}${EXTRACT_SUFX}
.endfor
.else
DISTFILES+=	${PORTNAME}-en-us-callie-48000-${PORTVERSION}${EXTRACT_SUFX}
.endif
.endif
.if defined(WITH_RUSSIAN)
.if defined(WITH_DOWNLOAD)
.for rate in ${BITRATES}
DISTFILES+=	${PORTNAME}-ru-RU-elena-${rate}-1.0.12${EXTRACT_SUFX}
.endfor
.else
DISTFILES+=	${PORTNAME}-ru-RU-elena-48000-1.0.12${EXTRACT_SUFX}
.endif
.endif
.if ! defined(WITH_ENGLISH) && ! defined(WITH_RUSSIAN)
BROKEN=	you must build with either English, Russian, or both
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
					echo "share/${BASE_PORTNAME}/sounds/en/us/callie/$${dir}/$${rate}/$${filename}" >> ${PLIST}; \
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
				echo "@rmdir share/${BASE_PORTNAME}/sounds/en/us/callie/$${dir}/$${rate}/" >> ${PLIST}; \
			done; \
		done; \
		${TOUCH} ${WRKDIR}/ENGLISH.done; \
	fi
	if [ "${WITH_RUSSIAN}" != "" -a ! -e "${WRKDIR}/RUSSIAN.done" ]; then \
		${ECHO_MSG} "====> Russian selected."; \
		for rate in ${BITRATES}; do \
			${ECHO_MSG} "WORKING on $${rate}!"; \
			for dir in `ls ${WRKSRC}/ru/RU/elena/`; do \
				${MKDIR} ${WRKDIR}/tmp/ru/RU/elena/$${dir}/$${rate}/; \
				for filename in `ls ${WRKSRC}/ru/RU/elena/$${dir}/48000`; do \
					echo "share/${BASE_PORTNAME}/sounds/ru/RU/elena/$${dir}/$${rate}/$${filename}" >> ${PLIST}; \
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
				echo "@rmdir share/${BASE_PORTNAME}/sounds/ru/RU/elena/$${dir}/$${rate}/" >> ${PLIST}; \
			done; \
		done; \
		${TOUCH} ${WRKDIR}/RUSSIAN.done; \
	fi

pre-install:
	@${RM} -rf ${PLIST}
	@cd ${WRKDIR}/tmp && ${FIND} * ! -type d | ${SORT} >> ${PLIST}; \
	${ECHO} .freeswitch-sounds >> ${PLIST}; \
	${SED} -i "" -e "s:^:share/${BASE_PORTNAME}/sounds/:" ${PLIST}; \
	${FIND} * -type d ! -empty | ${SORT} -r | ${SED} -e "s:^:@dirrm share/${BASE_PORTNAME}/sounds/:" | ${GREP} / >> ${PLIST}; \
	${ECHO} "@dirrmtry share/${BASE_PORTNAME}/sounds" >> ${PLIST}; \
	${ECHO} "@dirrmtry share/${BASE_PORTNAME}" >> ${PLIST};
	${CHMOD} -R 0755 ${WRKDIR}/tmp/

do-install:
	@${ECHO_MSG} "Installing files..."
	${MKDIR} ${PREFIX}/share/${BASE_PORTNAME}/sounds
	${TOUCH} ${PREFIX}/share/${BASE_PORTNAME}/sounds/.freeswitch-sounds
	(cd ${WRKDIR}/tmp/ &&${COPYTREE_SHARE} \* ${PREFIX}/share/${BASE_PORTNAME}/sounds/)

.include <bsd.port.mk>
