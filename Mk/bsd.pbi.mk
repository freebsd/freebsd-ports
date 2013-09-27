# $FreeBSD$
#
# Creates a PBI file from a port with just 'make pbi'
#
.if !defined(_INCLUDE_PBI_MK)

_INCLUDE_PBI_MK=	yes
PBI_MAINTAINER=		kmoore@FreeBSD.org

_PBIMAKEPORT=	pbi_makeport
_PBICREATE=	pbi_create
_PBIDIR=	pbi
_PBICONF=	${_PBIDIR}/pbi.conf

.PHONY: check-pbimanager pbi pbi-makeport pbi-generate pbi-create \
	clean-pbi clean-pbibuild

check-pbimanager:

	@set -- chk=""; \
	if [ -z "`which pbi_info`" ] ; then \
		cd ${PORTSDIR}/sysutils/pcbsd-utils && make install clean; \
	fi

pbi: pbi-generate

pbi-generate: check-pbimanager
	@_PBIPORT=`pwd | cut -d "/" -f4-`; \
	if [ ! -d ${PWD}/pbi ] ; then					\
		${ECHO_MSG} "===> Generating meta-data for ${PORTNAME}";	\
		${MKDIR} ${_PBIDIR};					\
		${MKDIR} ${_PBIDIR}/resources ${_PBIDIR}/scripts 	\
			${_PBIDIR}/xdg-desktop ${_PBIDIR}/xdg-menu 	\
			${_PBIDIR}/xgd-mime;				\
		${ECHO_CMD} "PBI_PROGNAME=\"${PORTNAME}\"" > ${_PBICONF};\
		${ECHO_CMD} "PBI_MAKEPORT=\"$${_PBIPORT}\"" >> ${_PBICONF};\
		PROGWEB=`cat ${DESCR} | awk '/^WWW:/ { print $$2; }'`;	\
		${ECHO_CMD} "PBI_PROGWEB=\"$${PROGWEB}\"" >> ${_PBICONF};\
		${ECHO_CMD} "PBI_PROGAUTHOR=\"The ${PORTNAME} team\""	\
			 >> ${_PBICONF};				\
		${ECHO_CMD} "PBI_UPDATEURL=\"http://update.pbidir.com\""\
			 >> ${_PBICONF};				\
		${ECHO_CMD} "export PBI_PROGNAME PBI_MAKEPORT "		\
			"PBI_PROGWEB " 					\
			"PBI_PROGAUTHOR PBI_UPDATEURL "	\
			"PBI_MKPORTBEFORE PBI_MKPORTAFTER PBI_MAKEOPTS"	\
			 >> ${_PBICONF};				\
	fi
	@${ECHO_MSG} "==> Generating PBI file"
	@${_PBIMAKEPORT} -c ${PWD}/pbi -o ${PWD} $${_PBIPORT}

clean-pbi:
	@${ECHO_MSG} "===> Cleaning PBI for ${PORTNAME}"
	@${RM} -rf ${_PBIDIR}

.endif
