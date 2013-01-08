# Created by: Eric F Crist <ecrist@secure-computing.net>
# $FreeBSD$

PORTNAME=	freeswitch
DISTVERSION=	1.0.22
CATEGORIES=	audio
MASTER_SITES=	http://files.freeswitch.org/
PKGNAMESUFFIX=	-sounds
DIST_SUBDIR=	${PORTNAME}${PORTNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeSwitch Sounds (All Bitrates)

PLIST=		${WRKDIR}/plist
NO_WRKSUBDIR=	yes
SHAREOWN=	${PORTNAME}
SHAREGRP=	${SHAREOWN}
USERS=		${PORTNAME}
GROUPS=		${USERS}
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

DOWNLOAD_DESC=	Download Sounds
8K_DESC=	8000Hz Audio Files
16K_DESC=	16000Hz Audio Files
32K_DESC=	32000Hz Audio Files
48K_DESC=	48000Hz Audio Files
ENGLISH_DESC=	Compile US English Language Sounds
FRENCH_DESC=	Compile French Canadian Language Sounds
RUSSIAN_DESC=	Compile Russian Language Sounds

OPTIONS_DEFINE=	DOWNLOAD

OPTIONS_SINGLE=	LANG
OPTIONS_SINGLE_LANG=	ENGLISH FRENCH RUSSIAN

OPTIONS_MULTI=	AUDIO
OPTIONS_MULTI_AUDIO=	8K 16K 32K 48K

OPTIONS_DEFAULT=	8K 16K ENGLISH
NO_OPTIONS_SORT=	yes

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDOWNLOAD)
BUILD_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.endif

.if ${PORT_OPTIONS:M8K}
BITRATES+=	8000
.endif
.if ${PORT_OPTIONS:M16K}
BITRATES+=	16000
.endif
.if ${PORT_OPTIONS:M32K}
BITRATES+=	32000
.endif
.if ${PORT_OPTIONS:M48K}
BITRATES+=	48000
.endif

.if ${PORT_OPTIONS:MENGLISH}
.if ${PORT_OPTIONS:MDOWNLOAD}
.for rate in ${BITRATES}
DISTFILES+=	${PORTNAME}${PKGNAMESUFFIX}-en-us-callie-${rate}-${DISTVERSION}${EXTRACT_SUFX}
.endfor
.else
DISTFILES+=	${PORTNAME}${PKGNAMESUFFIX}-en-us-callie-48000-${DISTVERSION}${EXTRACT_SUFX}
.endif
.endif
.if ${PORT_OPTIONS:MFRENCH}
.if ${PORT_OPTIONS:MDOWNLOAD}
.for rate in ${BITRATES}
DISTFILES+=	${PORTNAME}${PKGNAMESUFFIX}-fr-ca-june-${rate}-1.0.16${EXTRACT_SUFX}
.endfor
.else
DISTFILES+=	${PORTNAME}${PKGNAMESUFFIX}-fr-ca-june-48000-1.0.16${EXTRACT_SUFX}
.endif
.endif
.if ${PORT_OPTIONS:MRUSSIAN}
.if ${PORT_OPTIONS:MDOWNLOAD}
.for rate in ${BITRATES}
DISTFILES+=	${PORTNAME}${PKGNAMESUFFIX}-ru-RU-elena-${rate}-1.0.13${EXTRACT_SUFX}
.endfor
.else
DISTFILES+=	${PORTNAME}${PKGNAMESUFFIX}-ru-RU-elena-48000-1.0.13${EXTRACT_SUFX}
.endif
.endif

.if defined(FREESWITCH_VSCALE)
SCALE=${FREESWITCH_VSCALE}
.else
SCALE=0.2
.endif

.for opt in ${ALL_OPTIONS}
.if ${PORT_OPTIONS:M${opt}}
PLIST_SUB+=     ${opt}=""
.else
PLIST_SUB+=     ${opt}="@comment "
.endif
.endfor

do-build:
	@${ECHO_MSG} "===> Building for bitrates: ${BITRATES}"
	@${ECHO_MSG} "===> Download >>>${PORT_OPTIONS:MDOWNLOAD}<<<"
	@${ECHO_MSG} "===> Scaling audio to ${SCALE}"
	if [ -n "${PORT_OPTIONS:MENGLISH}" -a ! -e "${WRKDIR}/ENGLISH.done" ]; then \
		${ECHO_MSG} "====> English selected."; \
		for rate in ${BITRATES}; do \
			${ECHO_MSG} "WORKING on $${rate}!"; \
			for dir in `ls ${WRKSRC}/en/us/callie/`; do \
				${MKDIR} ${WRKDIR}/tmp/en/us/callie/$${dir}/$${rate}/; \
				for filename in `ls ${WRKSRC}/en/us/callie/$${dir}/48000`; do \
					echo "${DATADIR_REL}/sounds/en/us/callie/$${dir}/$${rate}/$${filename}" >> ${PLIST}; \
					if [ ! -e "${WRKDIR}/tmp/en/us/callie/$${dir}/$${rate}/$${filename}" ]; then \
						if [ "${PORT_OPTIONS:MDOWNLOAD}" = "true" ]; then \
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

	if [ -n "${PORT_OPTIONS:MFRENCH}"  -a ! -e "${WRKDIR}/FRENCH.done" ]; then \
		${ECHO_MSG} "====> French selected."; \
		for rate in ${BITRATES}; do \
			${ECHO_MSG} "WORKING on $${rate}!"; \
			 for dir in `ls ${WRKSRC}/fr/ca/june/`; do \
				${MKDIR} ${WRKDIR}/tmp/fr/ca/june/$${dir}/$${rate}/; \
					 for filename in `ls ${WRKSRC}/fr/ca/june/$${dir}/48000`; do \
					echo "${DATADIR_REL}/sounds/fr/ca/june/$${dir}/$${rate}/$${filename}" >> ${PLIST}; \
					if [ ! -e "${WRKDIR}/tmp/fr/ca/june/$${dir}/$${rate}/$${filename}" ]; then \
						if [ "${PORT_OPTIONS:MDOWNLOAD}" = "true" ]; then \
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

	if [ -n "${PORT_OPTIONS:MRUSSIAN}" -a ! -e "${WRKDIR}/RUSSIAN.done" ]; then \
		${ECHO_MSG} "====> Russian selected."; \
		for rate in ${BITRATES}; do \
			${ECHO_MSG} "WORKING on $${rate}!"; \
			for dir in `ls ${WRKSRC}/ru/RU/elena/`; do \
				${MKDIR} ${WRKDIR}/tmp/ru/RU/elena/$${dir}/$${rate}/; \
				for filename in `ls ${WRKSRC}/ru/RU/elena/$${dir}/48000`; do \
					echo "share/${DATADIR_REL}/sounds/ru/RU/elena/$${dir}/$${rate}/$${filename}" >> ${PLIST}; \
					if [ ! -e "${WRKDIR}/tmp/ru/RU/elena/$${dir}/$${rate}/$${filename}" ]; then \
						if [ "${PORT_OPTIONS:MDOWNLOAD}" = "true" ]; then \
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
