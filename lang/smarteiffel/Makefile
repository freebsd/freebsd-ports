# New ports collection makefile for:	SmartEiffel
# Date created:				Wed Dec 22 18:20:05 CET 1999
# Whom:					berend@pobox.com
#
# $FreeBSD$
#

PORTNAME=	smarteiffel
DISTVERSION=	1.2r6
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://except.com.ar/downloads/smarteiffel/
DISTNAME=	SmartEiffel-${DISTVERSION}

MAINTAINER=	berend@pobox.com
COMMENT=	SmartEiffel, the GNU compiler for the object-oriented language Eiffel

WRKSRC=		${WRKDIR}/SmartEiffel12

# We install in this directory
SEDIR=		${PREFIX}/${PORTNAME}-${DISTVERSION}

# We alias a directory to the installation directory
# so it is possible to easily switch between different builds
ALIASDIR=	${PREFIX}/SmartEiffel

# SmartEiffel needs this to find system.se
MAKE_ENV+=	SmartEiffel=${WRKSRC}/sys/system.se
ALL_TARGET=
PLIST_SUB+=	PORTVERSION=${DISTVERSION}

SUB_FILES=	pkg-install pkg-message

post-patch:
	@${REINPLACE_CMD} \
		-e 's|^.*c_compiler_options:.*$$|c_compiler_options: ${CFLAGS}|' \
		-e 's|^.*cpp_compiler_options:.*$$|cpp_compiler_options: ${CXXFLAGS}|' \
			${WRKSRC}/install/gcc.rc

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
		${CP} -pR ${WRKSRC}/* ${SEDIR})
	@${SED} -i .orig -e "s,${WRKSRC},${SEDIR},g" ${SEDIR}/sys/system.se
	@${RM} ${SEDIR}/sys/system.se.orig
	@${SED} -i .orig -e "s,${WRKSRC},${SEDIR},g" ${SEDIR}/lib/loadpath.se
	@${RM} ${SEDIR}/lib/loadpath.se.orig
	@${SED} -i .orig -e "s,${WRKSRC},${SEDIR},g" ${SEDIR}/tools/loadpath.se
	@${RM} ${SEDIR}/tools/loadpath.se.orig
	@${SED} -i .orig -e "s,${WRKSRC},${SEDIR},g" ${SEDIR}/tutorial/loadpath.se
	@${RM} ${SEDIR}/tutorial/loadpath.se.orig

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
