# New ports collection makefile for:	SmallEiffel
# Date created:				Wed Dec 22 18:20:05 CET 1999
# Whom:					berend@pobox.com
#
# $FreeBSD$
#

PORTNAME=	smalleiffel
PORTVERSION=	0.76.b4
CATEGORIES=	lang
MASTER_SITES=	http://people.FreeBSD.org/~sada/distfiles/

MAINTAINER=	berend@pobox.com

WRKSRC=		${WRKDIR}/SmallEiffel

# SmallEiffel needs this to find system.se
MAKE_ENV+=	SmallEiffel=${WRKSRC}/sys/system.se
ALL_TARGET=
PLIST_SUB=	PKGNAME=${PKGNAME}

PKGMESSAGE=	${WRKDIR}/MESSAGE
PKGINSTALL=	${WRKDIR}/INSTALL

# We install in this directory
SEDIR=		${PREFIX}/${PKGNAME}

# We alias a directory to the installation directory
# so it is possible to easily switch between different builds
ALIASDIR=	${PREFIX}/SmallEiffel

# Make sure we can set the symbolic link SmallEiffel
# to the actual release directory.
do-install:
	@(if test -e ${ALIASDIR} ; then \
	    if ! test -L ${ALIASDIR} ; then \
		${ECHO} "Make sure ${ALIASDIR} is a symbolic link"; \
		${ECHO} "or does not exist. This directory will point to "; \
		${ECHO} "the actual SmallEiffel installation directory."; \
		exit 1; \
	    fi; \
	    ${RM} ${ALIASDIR}; \
	fi; \
	${LN} -fs ${SEDIR} ${ALIASDIR})
	@(if test -e ${SEDIR} ; then ${RM} -rf ${SEDIR}; fi; \
	    ${MKDIR} ${SEDIR}; \
	    ${CP} -pR ${WRKSRC}/* ${SEDIR}; \
	    ${ECHO} ./ > ${SEDIR}/sys/loadpath.UNIX; \
	    ${ECHO} ${SEDIR}/lib_std/ >> ${SEDIR}/sys/loadpath.UNIX; \
	    ${ECHO} ${SEDIR}/lib_iterator/ >> ${SEDIR}/sys/loadpath.UNIX; \
	    ${ECHO} ${SEDIR}/lib_random/ >> ${SEDIR}/sys/loadpath.UNIX; \
	    ${ECHO} ${SEDIR}/lib_number/ >> ${SEDIR}/sys/loadpath.UNIX; \
	    ${ECHO} ${SEDIR}/lib_show/ >> ${SEDIR}/sys/loadpath.UNIX; \
	    ${ECHO} ${SEDIR}/lib_se/ >> ${SEDIR}/sys/loadpath.UNIX)
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGDIR}/pkg-message \
		> ${PKGMESSAGE}
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGDIR}/pkg-install \
		> ${PKGINSTALL}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# below is the location of original distributions.
#MASTER_SITES=	ftp://ftp.loria.fr/pub/loria/genielog/SmallEiffel/se.beta_test
#DISTNAME=	se
