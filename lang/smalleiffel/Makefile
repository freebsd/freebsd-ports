# New ports collection makefile for:	SmallEiffel
# Date created:				Wed Dec 22 18:20:05 CET 1999
# Whom:					berend@pobox.com
#
# $FreeBSD$
#

PORTNAME=	smalleiffel
PORTVERSION=	0.76
PORTEPOCH=	1	# Version numbering is negative
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.loria.fr/pub/loria/genielog/SmallEiffel/Oldies/
DISTNAME=	se-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	berend@pobox.com

WRKSRC=		${WRKDIR}/SmallEiffel

# We install in this directory
SEDIR=		${PREFIX}/${PORTNAME}-${PORTVERSION}

# We alias a directory to the installation directory
# so it is possible to easily switch between different builds
ALIASDIR=	${PREFIX}/SmallEiffel

# SmallEiffel needs this to find system.se
MAKE_ENV+=	SmallEiffel=${WRKSRC}/sys/system.se
ALL_TARGET=

PKGMESSAGE=	${WRKDIR}/MESSAGE
PKGINSTALL=	${WRKDIR}/INSTALL

# Make sure we can set the symbolic link SmallEiffel
# to the actual release directory.
do-install:
	@(if ${TEST} -e ${ALIASDIR} ; then \
	    if ! ${TEST} -L ${ALIASDIR} ; then \
		${ECHO} "Make sure ${ALIASDIR} is a symbolic link"; \
		${ECHO} "or does not exist. This directory will point to "; \
		${ECHO} "the actual SmallEiffel installation directory."; \
		exit 1; \
	    fi; \
	    ${RM} ${ALIASDIR}; \
	fi; \
	${LN} -fs ${SEDIR} ${ALIASDIR})
	@(if ${TEST} -e ${SEDIR} ; then ${RM} -rf ${SEDIR}; fi; \
	    ${MKDIR} ${SEDIR}; \
	    ${CP} -pR ${WRKSRC}/* ${SEDIR}; \
	    ${ECHO_CMD} ./ > ${SEDIR}/sys/loadpath.UNIX; \
	    ${ECHO_CMD} ${SEDIR}/lib_std/ >> ${SEDIR}/sys/loadpath.UNIX; \
	    ${ECHO_CMD} ${SEDIR}/lib_iterator/ >> ${SEDIR}/sys/loadpath.UNIX; \
	    ${ECHO_CMD} ${SEDIR}/lib_random/ >> ${SEDIR}/sys/loadpath.UNIX; \
	    ${ECHO_CMD} ${SEDIR}/lib_number/ >> ${SEDIR}/sys/loadpath.UNIX; \
	    ${ECHO_CMD} ${SEDIR}/lib_show/ >> ${SEDIR}/sys/loadpath.UNIX; \
	    ${ECHO_CMD} ${SEDIR}/lib_se/ >> ${SEDIR}/sys/loadpath.UNIX)
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGDIR}/pkg-message \
		> ${PKGMESSAGE}
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGDIR}/pkg-install \
		> ${PKGINSTALL}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
