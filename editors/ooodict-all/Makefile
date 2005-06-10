# New ports collection makefile for: OpenOffice.org Spell Checking Dictionaries
# Date created:         Tue Aug 10 24:00:00 UTC 2002
# Whom:         Martin Blapp <mbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ooodict
PORTVERSION=	1.20050518
CATEGORIES+=	editors
MASTER_SITES+=	http://ftp.gwdg.de/pub/misc/openoffice/contrib/dictionaries/ \
		http://ftp.services.openoffice.org/pub/OpenOffice.org/contrib/dictionaries/
DISTFILES+=	${LANGDIST}
DISTFILES+=	${HYPHDIST}
DISTFILES+=	${THESDIST}

MAINTAINER=     openoffice@FreeBSD.org
COMMENT?=	MySpell dictionaries for OpenOffice.org

USE_ZIP=	yes
EXTRACT_ONLY=

.if !defined(LANGDIST)
DICTMETAPORT=	yes
LANGDIST?=	af_ZA.zip bg_BG.zip ca_ES.zip cs_CZ.zip cy_GB.zip \
		da_DK.zip de_AT.zip de_DE.zip de_CH.zip el_GR.zip \
		en_AU.zip en_CA.zip en_GB.zip en_NZ.zip en_US.zip \
		es_ES.zip es_MX.zip fo_FO.zip fr_BE.zip fr_FR.zip \
		ga_IE.zip gd_GB.zip gl_ES.zip he_IL.zip hr_HR.zip \
		hu_HU.zip id_ID.zip it_IT.zip ku_TR.zip lt_LT.zip \
		mg_MG.zip mi_NZ.zip ms_MY.zip nb_NO.zip nl_NL.zip \
		nn_NO.zip ny_MW.zip pl_PL.zip pt_PT.zip pt_BR.zip \
		ro_RO.zip rw_RW.zip ru_RU.zip sk_SK.zip sl_SI.zip \
		sv_SE.zip sw_KE.zip tl_PH.zip tn_ZA.zip uk_UA.zip \
		zu_ZA.zip

HYPHDIST?=	hyph_bg_BG.zip hyph_cs_CZ.zip hyph_da_DK.zip \
		hyph_de_CH.zip hyph_de_DE.zip hyph_el_GR.zip \
		hyph_en_CA.zip hyph_en_AU.zip hyph_en_CA.zip \
		hyph_en_GB.zip hyph_en_NZ.zip hyph_en_US.zip \
		hyph_es_ES.zip hyph_es_MX.zip hyph_fr_BE.zip \
		hyph_fr_FR.zip hyph_ga_IE.zip hyph_id_ID.zip \
		hyph_it_IT.zip hyph_nl_NL.zip hyph_pl_PL.zip \
		hyph_pt_BR.zip hyph_pt_PT.zip hyph_ro_RO.zip \
		hyph_ru_RU.zip hyph_sk_SK.zip hyph_sl_SI.zip \
		hyph_sv_SE.zip hyph_uk_UA.zip

THESDIST?=	thes_bg_BG.zip thes_cs_CZ.zip thes_de_DE.zip \
		thes_es_ES.zip thes_fr_FR.zip thes_hu_HU.zip \
		thes_it_IT.zip thes_pl_PL.zip thes_sk_SK.zip
.endif
CUT?=	/usr/bin/cut

.include <bsd.port.pre.mk>

.if !defined(INSTALLATION_BASEDIR)
INSTALLATION_BASEDIR=	OpenOffice.org1.1.4
.if defined(RDEP)
BUILD_DEPENDS=	${DICT_LIST_INST}:${RDEP}
RUN_DEPENDS=	${DICT_LIST_INST}:${RDEP}
.else
BUILD_DEPENDS=	${DICT_LIST_INST}:${PORTSDIR}/editors/openoffice-1.1
RUN_DEPENDS=	${DICT_LIST_INST}:${PORTSDIR}/editors/openoffice-1.1
.endif
.endif
# needed for install stage
RUN_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip

DIST_SUBDIR=		openoffice
DICT_DIR=		${INSTALLATION_BASEDIR}/share/dict/ooo
DICT_PATH=		${LOCALBASE}/${DICT_DIR}
DICT_LIST_INST=		${DICT_PATH}/dictionary.lst
DICT_PATH_PLIST=	"%D/${DICT_DIR}"
DICT_LIST=		${DICT_PATH_PLIST}/dictionary.lst
PLIST=			${WRKDIR}/pkg-plist

.if defined(LANGPREFIX)
PKGNAMEPREFIX=	${LANGPREFIX}-
.endif
.if defined(LANGSUFFIX)
PKGNAMESUFFIX=	-${LANGSUFFIX}
.endif

.if exists(${.CURDIR}/pkg-descr)
DESCR=		${.CURDIR}/pkg-descr
.endif

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

EXTRACT_CMD_L?=		unzip
EXTRACT_BEFORE_ARGS_L?=	-q -o
EXTRACT_AFTER_ARGS_L?=	-d ${PREFIX}/${DICT_DIR}

pre-install:
.if ! exists(${WRKDIR}/pkg-plist)
	@${TOUCH} ${WRKDIR}/pkg-plist
.endif

do-install:

post-install:
	@for file in ${LANGDIST}; do \
		ABRV=`${ECHO_CMD} $${file} | ${SED} -e 's|\.zip||'`; \
		LANGUAGE=`${ECHO_CMD} $${ABRV} | ${SED} -e 's|_.*||'`; \
		COUNTRY=`${ECHO_CMD} $${ABRV} | ${SED} -e 's|.*_||' | ${CUT} -c 1,2`; \
		if ! ( ${GREP} "DICT $${LANGUAGE} $${COUNTRY}" \
		    ${DICT_LIST_INST} > /dev/null && test -z $${DICT_OVERWRITE} ) ; \
		then  \
			if ! (cd ${DICT_PATH} && ${EXTRACT_CMD_L} \
				${EXTRACT_BEFORE_ARGS_L} \
				${_DISTDIR}/$${file} '*.aff' '*.dic' \
				${EXTRACT_AFTER_ARGS_L}) ; \
			then \
				${ECHO} "Extracting of $${file} failed"; \
				exit 1; \
			fi ; \
			${ECHO_MSG} "===>   Register spelling dictionary $${LANGUAGE}_$${COUNTRY}"; \
			${ECHO} "@exec ${ECHO} \"DICT $${LANGUAGE} $${COUNTRY} $${ABRV}\" \
			    >> ${DICT_LIST}" >> ${TMPPLIST} ; \
			${ECHO_CMD} "DICT $${LANGUAGE} $${COUNTRY} $${ABRV}" >> ${DICT_LIST_INST} ; \
			cd ${PREFIX} && ${FIND} -s ${DICT_DIR} -type f | \
			    ${GREP} $${LANGUAGE}_$${COUNTRY} >> ${TMPPLIST} ; \
			cd ${PREFIX} && ${FIND} -s ${DICT_DIR} -type f | \
			    ${GREP} $${LANGUAGE}_$${COUNTRY} | \
			    ${XARGS} chmod 755 ; \
			${ECHO} "@unexec ${CP} ${DICT_LIST} \
			    ${DICT_LIST}.$${LANGUAGE}_$${COUNTRY}" >> ${TMPPLIST} ; \
			${ECHO} "@unexec \
			    if ! ( ${CAT} ${DICT_LIST}.$${LANGUAGE}_$${COUNTRY} | \
				${GREP} -v -e '^DICT.*$${LANGUAGE}_$${COUNTRY}' > ${DICT_LIST} ) ; then \
					${ECHO_MSG} '===>   Notice: ${DICT_LIST} is empty' ; \
			    fi" >> ${TMPPLIST} ; \
			${ECHO} "@unexec ${RM} ${DICT_LIST}.$${LANGUAGE}_$${COUNTRY}" \
			    >> ${TMPPLIST} ; \
			case $${ABRV} in \
			de_DE) \
				${ECHO_MSG} "===>   Cross-register spelling dictionary $${ABRV} to $${LANGUAGE}_AT"; \
				${LN} -fs ${DICT_PATH}/de_DE.aff ${DICT_PATH}/de_AT.aff; \
				${ECHO} "@exec ${ECHO} \"DICT $${LANGUAGE} AT de_AT\" \
				    >> ${DICT_LIST}" >> ${TMPPLIST} ; \
				${ECHO_CMD} "DICT $$LANGUAGE AT $${ABRV}" >> ${DICT_LIST_INST} ; \
				cd ${PREFIX} && ${FIND} -s ${DICT_DIR} -type f \
				    | ${GREP} $${LANGUAGE}_AT >> ${TMPPLIST} ; \
				cd ${PREFIX} && ${FIND} -s ${DICT_DIR} -type l \
				    | ${GREP} $${LANGUAGE}_AT >> ${TMPPLIST} ; \
				${ECHO} "@unexec ${CP} ${DICT_LIST} \
				    ${DICT_LIST}.$${LANGUAGE}_AT" >> ${TMPPLIST} ; \
				${ECHO} "@unexec \
				    if ! ( ${CAT} ${DICT_LIST}.$${LANGUAGE}_AT | \
					${GREP} -v -e '^DICT.*$${LANGUAGE}_AT' > ${DICT_LIST} ) ;  then \
					${ECHO_MSG} '===>   Notice: ${DICT_LIST} is empty' ; \
				    fi" >> ${TMPPLIST} ; \
				${ECHO} "@unexec ${RM} ${DICT_LIST}.$${LANGUAGE}_AT" \
				    >> ${TMPPLIST} ; \
				;; \
			esac \
		else \
				${ECHO_MSG} "===>   Dictionary $${LANGUAGE}_$${COUNTRY} already registered"; \
				${ECHO_MSG} "===>   Set DICT_OVERWRITE=YES if you like to overwrite it"; \
		fi ; \
	done
	@for file in ${HYPHDIST}; do \
		ABRV=`${ECHO_CMD} $${file} | ${SED} -e 's|\.zip||' -e 's|^hyph_||'`; \
		LANGUAGE=`${ECHO_CMD} $${ABRV} | ${SED} -e 's|_.*||'`; \
		COUNTRY=`${ECHO_CMD} $${ABRV} | ${SED} -e 's|.*_||' | ${CUT} -c 1,2 | ${TR} "[:lower:]" "[:upper:]"` ; \
		if ! ( ${GREP} "HYPH $${LANGUAGE} $${COUNTRY}" \
		    ${DICT_LIST_INST} > /dev/null && test -z $${DICT_OVERWRITE} ) ; \
		then  \
			if ! (cd ${DICT_PATH} && ${EXTRACT_CMD_L} \
				${EXTRACT_BEFORE_ARGS_L} \
				${_DISTDIR}/$${file} '*.dic' \
				${EXTRACT_AFTER_ARGS_L}) ; \
			then \
				${ECHO} "Extracting of $${file} failed"; \
				exit 1; \
			fi ; \
			${ECHO_MSG} "===>   Register hyphenation dictionary hyph_$${ABRV}"; \
			${ECHO} "@exec ${ECHO} \"HYPH $${LANGUAGE} $${COUNTRY} hyph_$${ABRV}\" \
			    >> ${DICT_LIST}" >> ${TMPPLIST} ; \
			${ECHO_CMD} "HYPH $${LANGUAGE} $${COUNTRY} hyph_$${ABRV}" >> ${DICT_LIST_INST} ; \
			cd ${PREFIX} && ${FIND} -s ${DICT_DIR} -type f | \
			    ${GREP} hyph_$${ABRV}.dic >> ${TMPPLIST} ; \
			cd ${PREFIX} && ${FIND} -s ${DICT_DIR} -type f | \
			    ${GREP} hyph_$${ABRV}.dic | ${XARGS} chmod 755 ; \
			${ECHO} "@unexec ${CP} ${DICT_LIST} \
			    ${DICT_LIST}.hyph_$${LANGUAGE}_$${COUNTRY}" >> ${TMPPLIST} ; \
			${ECHO} "@unexec \
			    if ! ( ${CAT} ${DICT_LIST}.hyph_$${LANGUAGE}_$${COUNTRY} | \
				${GREP} -v -e '^HYPH.*hyph_$${ABRV}' > ${DICT_LIST} ) ; then \
					${ECHO_MSG} '===>   Notice: ${DICT_LIST} is empty' ; \
			    fi" >> ${TMPPLIST} ; \
			${ECHO} "@unexec ${RM} ${DICT_LIST}.hyph_$${LANGUAGE}_$${COUNTRY}" \
			    >> ${TMPPLIST} ; \
		else \
				${ECHO_MSG} "===>   Hyphenation Dictionary $${LANGUAGE}_$${COUNTRY} already registered"; \
				${ECHO_MSG} "===>   Set DICT_OVERWRITE=YES if you like to overwrite it"; \
		fi ; \
	done
	@for file in ${THESDIST}; do \
		ABRV=`${ECHO_CMD} $${file} | ${SED} -e 's|\.zip||' -e 's|^thes_||'`; \
		LANGUAGE=`${ECHO_CMD} $${ABRV} | ${SED} -e 's|_.*||'`; \
		COUNTRY=`${ECHO_CMD} $${ABRV} | ${SED} -e 's|.*_||' | ${CUT} -c 1,2 | ${TR} "[:lower:]" "[:upper:]"` ; \
		if ! ( ${GREP} "THES $${LANGUAGE} $${COUNTRY}" \
			${DICT_LIST_INST} > /dev/null && test -z $${DICT_OVERWRITE} ) ; \
		then \
			if ! (cd ${DICT_PATH} && ${EXTRACT_CMD_L} \
				${EXTRACT_BEFORE_ARGS_L} \
				${_DISTDIR}/$${file} '*.dat' '*.idx' \
				${EXTRACT_AFTER_ARGS_L}) ; \
			then \
				${ECHO} "Extracting of $${file} failed"; \
				exit 1; \
			fi ; \
			${ECHO_MSG} "===>   Register thesaurus dictionary th_$${ABRV}"; \
			${ECHO} "@exec ${ECHO} \"THES $${LANGUAGE} $${COUNTRY} th_$${ABRV}\" \
				>> ${DICT_LIST}" >> ${TMPPLIST} ; \
			${ECHO_CMD} "THES $${LANGUAGE} $${COUNTRY} th_$${ABRV}" >> ${DICT_LIST_INST} ; \
			cd ${PREFIX} && ${FIND} -s ${DICT_DIR} -type f | \
				${GREP} th_$${ABRV} >> ${TMPPLIST} ; \
			cd ${PREFIX} && ${FIND} -s ${DICT_DIR} -type f | \
				${GREP} th_$${ABRV} | \
				${XARGS} chmod 755 ; \
			${ECHO} "@unexec ${CP} ${DICT_LIST} \
				${DICT_LIST}.th_$${LANGUAGE}_$${COUNTRY}" >> ${TMPPLIST} ; \
			${ECHO} "@unexec \
			if ! ( ${CAT} ${DICT_LIST}.th_$${LANGUAGE}_$${COUNTRY} | \
				${GREP} -v -e '^THES.*th_$${ABRV}' > ${DICT_LIST} ) ; then \
					${ECHO_MSG} '===>   Notice: ${DICT_LIST} is empty' ; \
			fi" >> ${TMPPLIST} ; \
			${ECHO} "@unexec ${RM} ${DICT_LIST}.th_$${LANGUAGE}_$${COUNTRY}" \
				>> ${TMPPLIST} ; \
		else \
			${ECHO_MSG} "===>   THESAURUS Dictionary $${LANGUAGE}_$${COUNTRY} already registered"; \
			${ECHO_MSG} "===>   Set DICT_OVERWRITE=YES if you like to overwrite it"; \
		fi ; \
	done

.include <bsd.port.post.mk>
