# Ports collection makefile for: freeswitch-sounds
# Date created: May 11, 2010
# Whom: Eric F Crist <ecrist@secure-computing.net>
#
# $FreeBSD$
#

PORTNAME=       freeswitch
PORTVERSION=    1.0.13
CATEGORIES=     audio
MASTER_SITES=	http://files.freeswitch.org/
PKGNAMESUFFIX=	-sounds
DIST_SUBDIR=    freeswitch-sounds

MAINTAINER=     ecrist@secure-computing.net
COMMENT=        FreeSwitch Sounds (All Bitrates)

PLIST= ${WRKDIR}/plist
NO_WRKSUBDIR=   yes

OPTIONS=        8K           "Compile sounds for 8K" on \
		16K          "Compile sounds for 16K" on \
		32K          "Compile sounds for 32K" on \
		48K          "Compile sounds for 48K" on \
		ENGLISH      "Compile English Language Sounds" on \
		RUSSIAN      "Compile Russian Language Sounds" off

.include <bsd.port.options.mk>
.if defined(WITH_ENGLISH)
DISTFILES+=    ${PORTNAME}${PKGNAMESUFFIX}-en-us-callie-48000-${PORTVERSION}${EXTRACT_SUFX}
.endif
.if defined(WITH_RUSSIAN)
DISTFILES+=    ${PORTNAME}${PKGNAMESUFFIX}-ru-RU-elena-48000-1.0.12${EXTRACT_SUFX}
.endif
.if ! defined(WITH_ENGLISH) && ! defined(WITH_RUSSIAN)
BROKEN=	"You must build with either English, Russian, or both"
.endif
.if ! defined(WITH_8K) && ! defined(WITH_16K) && ! defined(WITH_32K) && \
	! defined(WITH_48K)
BROKEN= "You must build with at least one of 8K, 16K, 32K, or 48K sounds"
.endif

.if defined(WITH_8K)
BUILD_DEPENDS+=  sox:${PORTSDIR}/audio/sox
BITRATES+= 8000
.endif
.if defined(WITH_16K)
BUILD_DEPENDS+=  sox:${PORTSDIR}/audio/sox
BITRATES+= 16000
.endif
.if defined(WITH_32K)
BUILD_DEPENDS+=  sox:${PORTSDIR}/audio/sox
BITRATES+= 32000
.endif
.if defined(WITH_48K)
BITRATES+= 48000
.endif

#RUN_DEPENDS+= freeswitch:${PORTSDIR}/net/freeswitch-core

do-build:
	@${ECHO_MSG} "Building for bitrates: ${BITRATES}"
	if [ "${WITH_ENGLISH}" != "" -a ! -e "${WRKDIR}/ENGLISH.done" ]; then \
		for rate in ${BITRATES}; do \
			${ECHO_MSG} "WORKING on $${rate}!"; \
			if [ "$${rate}" -eq "48000" ]; then \
				${CP} -R ${WRKSRC}/en/us/callie/ ${WRKDIR}/tmp/en/us/callie/; \
			else \
				for dir in `ls ${WRKSRC}/en/us/callie/`; do \
					${MKDIR} ${WRKDIR}/tmp/en/us/callie/$${dir}/$${rate}/; \
					echo "@rmdir ${LOCALBASE}/share/freeswitch/sounds/en/us/callie/$${dir}/$${rate}/" >> ${PLIST}; \
					for filename in `ls ${WRKSRC}/en/us/callie/$${dir}/48000`; do \
						echo "${LOCALBASE}/share/freeswitch/sounds/en/us/callie/$${dir}/$${rate}/$${filename}" >> ${PLIST}; \
						if [ ! -e "${WRKDIR}/tmp/en/us/callie/$${dir}/$${rate}/$${filename}" ]; then \
							${ECHO_MSG} "${LOCALBASE}/bin/sox -v 0.2 ${WRKSRC}/en/us/callie/$${dir}/48000/$${filename} -r $${rate} -c 1 ${WRKDIR}/tmp/en/us/callie/$${dir}/$${rate}/$${filename}"; \
							${LOCALBASE}/bin/sox -v 0.2 "${WRKSRC}/en/us/callie/$${dir}/48000/$${filename}" -r $${rate} -c 1 "${WRKDIR}/tmp/en/us/callie/$${dir}/$${rate}/$${filename}"; \
						fi \
					done; \
				done; \
			fi \
		done; \
		${TOUCH} ${WRKDIR}/ENGLISH.done; \
	fi
	if [ "${WITH_RUSSIAN}" != "" -a ! -e "${WRKDIR}/RUSSIAN.done" ]; then \
		for rate in ${BITRATES}; do \
			${ECHO_MSG} "WORKING on $${rate}!"; \
			if [ "$${rate}" -eq "48000" ]; then \
				${CP} -R ${WRKSRC}/ru/RU/elena/ ${WRKDIR}/tmp/ru/RU/elena/; \
			else \
				for dir in `ls ${WRKSRC}/ru/RU/elena/`; do \
					${MKDIR} ${WRKDIR}/tmp/ru/RU/elena/$${dir}/$${rate}/; \
					echo "@rmdir ${DATADIR}/sounds/ru/RU/elena/$${dir}/$${rate}/" >> ${PLIST}; \
					for filename in `ls ${WRKSRC}/ru/RU/elena/$${dir}/48000`; do \
						echo "${DATADIR}/sounds/ru/RU/elena/$${dir}/$${rate}/$${filename}" >> ${PLIST}; \
						if [ ! -e "${WRKDIR}/tmp/ru/RU/elena/$${dir}/$${rate}/$${filename}" ]; then \
							${ECHO_MSG} "${LOCALBASE}/bin/sox -v 0.2 ${WRKSRC}/ru/RU/elena/$${dir}/48000/$${filename} -r $${rate} -c 1 ${WRKDIR}/tmp/ru/RU/elena/$${dir}/$${rate}/$${filename}"; \
							${LOCALBASE}/bin/sox -v 0.2 "${WRKSRC}/ru/RU/elena/$${dir}/48000/$${filename}" -r $${rate} -c 1 "${WRKDIR}/tmp/ru/RU/elena/$${dir}/$${rate}/$${filename}"; \
						fi \
					done; \
				done; \
			fi \
		done; \
		${TOUCH} ${WRKDIR}/RUSSIAN.done; \
	fi

pre-install:
	@${RM} -rf ${PLIST}
	@cd ${WRKDIR}/tmp && ${FIND} * ! -type d | ${SORT} >> ${PLIST}; \
	${ECHO} .freeswitch-sounds >> ${PLIST}; \
	${SED} -i "" -e "s:^:%%DATADIR%%/sounds/:" ${PLIST}; \
	${FIND} * -type d ! -empty | ${SORT} -r | ${SED} -e "s:^:@dirrm %%DATADIR%%/sounds/:" | ${GREP} / >> ${PLIST}; \
	${ECHO} "@dirrmtry %%DATADIR%%/sounds 2> /dev/null || /usr/bin/true" >> ${PLIST}; \
	${ECHO} "@dirrmtry %%DATADIR%% 2> /dev/null || /usr/bin/true" >> ${PLIST};
	${CHMOD} -R 0755 ${WRKDIR}/tmp/

do-install:
	@${ECHO_MSG} "Installing files..."
	${MKDIR} ${DATADIR}/sounds
	${TOUCH} ${DATADIR}/sounds/.freeswitch-sounds
	(cd ${WRKDIR}/tmp/ &&${COPYTREE_SHARE} \* ${DATADIR}/sounds/)

.include <bsd.port.mk>
