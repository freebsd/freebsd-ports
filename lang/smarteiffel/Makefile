# New ports collection makefile for:	SmartEiffel
# Date created:				Wed Dec 22 18:20:05 CET 1999
# Whom:					berend@pobox.com
#
# $FreeBSD$
#

PORTNAME=	smarteiffel
PORTVERSION=	1.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.loria.fr/pub/loria/SmartEiffel/Oldies/
DISTNAME=	se-${PORTVERSION}

MAINTAINER=	berend@pobox.com
COMMENT=	SmartEiffel, the GNU compiler for the object-oriented language Eiffel

WRKSRC=		${WRKDIR}/SmartEiffel

# We install in this directory
SEDIR=		${PREFIX}/${PORTNAME}-${PORTVERSION}

# We alias a directory to the installation directory
# so it is possible to easily switch between different builds
ALIASDIR=	${PREFIX}/SmartEiffel

# SmartEiffel needs this to find system.se
MAKE_ENV+=	SmartEiffel=${WRKSRC}/sys/system.se
ALL_TARGET=
USE_BZIP2=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

PKGMESSAGE=	${WRKDIR}/MESSAGE
PKGINSTALL=	${WRKDIR}/INSTALL

# Make sure we can set the symbolic link SmartEiffel
# to the actual release directory.
do-install:
	@(if ${TEST} -e ${ALIASDIR} ; then \
		if ! ${TEST} -L ${ALIASDIR} ; then \
		${ECHO} "Make sure ${ALIASDIR} is a symbolic link"; \
		${ECHO} "or does not exist. This directory will point to "; \
		${ECHO} "the actual SmartEiffel installation directory."; \
		exit 1; \
		fi; \
		${RM} ${ALIASDIR}; \
	fi; \
	${LN} -fs ${SEDIR} ${ALIASDIR})
	@(if ${TEST} -e ${SEDIR} ; then ${RM} -rf ${SEDIR}; fi; \
		${MKDIR} ${SEDIR}; \
		${CP} -pR ${WRKSRC}/* ${SEDIR}; \
		${ECHO_CMD} ./ > ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/lib/kernel/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/lib/base/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/lib/io/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/lib/iterator/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/lib/random/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/lib/number/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/lib/sorting/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/lib/time/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/lib/scoop/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/lib/misc/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/tools/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/tools/expression/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/tools/instruction/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/tools/e_type/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/tools/feature/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/tools/run_feature/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/tools/misc/ >> ${SEDIR}/sys/loadpath.UNIX; \
		${ECHO_CMD} ${SEDIR}/tutorial/ >> ${SEDIR}/sys/loadpath.UNIX)
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGDIR}/pkg-message \
		> ${PKGMESSAGE}
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGDIR}/pkg-install \
		> ${PKGINSTALL}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
