# New ports collection makefile for:	SmallEiffel
# Date created:				Wed Dec 22 18:20:05 CET 1999
# Whom:					berend@pobox.com
#
# $FreeBSD$
#

PORTNAME=	smalleiffel
PORTVERSION=	0.77
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.loria.fr/pub/loria/genielog/SmallEiffel/
DISTNAME=	se
EXTRACT_SUFX=	.tgz

MAINTAINER=	berend@pobox.com

WRKSRC=		${WRKDIR}/SmallEiffel

# We install in this directory
SEDIR=		${PREFIX}/${PKGNAME}

# We alias a directory to the installation directory
# That we we can easily switch between different builds
ALIASDIR=	${PREFIX}/SmallEiffel

# SmallEiffel needs this to find system.se
MAKE_ENV+=	SmallEiffel=${WRKSRC}/sys/system.se
ALL_TARGET=

PKGMESSAGE=	${WRKDIR}/MESSAGE
PKGINSTALL=	${WRKDIR}/INSTALL

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
	    ${CP} -pR ${WRKSRC}/* ${SEDIR})
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGDIR}/MESSAGE \
		> ${PKGMESSAGE}
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" ${PKGDIR}/INSTALL \
		> ${PKGINSTALL}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
