# New ports collection makefile for:	festival
# Date created:        			2000-06-11
# Whom:					Trevor Johnson
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.11 1999/12/28 04:19:58 wiz Exp $
# $FreeBSD$
#

PORTNAME=	festival
PORTVERSION=	1.95
PORTREVISION=	1
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL}
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTFILES=	${DISTNAME}-beta.tar.gz 	\
		speech_tools-1.2.95-beta.tar.gz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Multi-lingual speech synthesis system

#LIB_DEPENDS=	audio:${PORTSDIR}/audio/nas \
#		esd:${PORTSDIR}/audio/esound

DIST_SUBDIR=	festival

CONFIGURE_WRKSRC=	${WRKDIR}/festival
USE_AUTOCONF=	yes
USE_GMAKE=	yes
SPEECHTOOLS=	${WRKSRC}/speech_tools
FESTIVAL=	${WRKSRC}/festival
FHOME=		${PREFIX}/share/festival
MAKE_ENV+=	GCC="${CC}" \
		GXX="${CXX}" \
		EST_HOME=${SPEECHTOOLS} \
		EGCS_CC="${CC}" \
		EGCS_CXX="${CXX}" \
		CC="${CC}" \
		CXX="${CXX}"
MAN1=		festival.1 festival_client.1
WRKSRC=		${WRKDIR}

do-build:
.for ii in speech_tools festival
	@(cd ${WRKDIR}/${ii}; \
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} Makefile ${MAKE_ARGS})
.endfor

.include <bsd.port.pre.mk>

do-configure:
.for d in speech_tools festival
	@cd ${WRKDIR}/$d && \
		if ! ${SETENV} CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}; then \
		${ECHO_CMD} "===>  configuration script for $d failed."; \
		${FALSE}; \
	fi
	# This step helps non-i386 systems and is harmless on i386
	-${LN} -s ix86_FreeBSD.mak ${WRKDIR}/$d/config/systems/${ARCH}_unknown.mak
	${REINPLACE_CMD} -E -e 's,^(CC|CXX) *=,\1 ?=,' \
	    -e 's,^(CFLAGS|CXXFLAGS) *=,\1 +=,'	\
	    -e 's,^OPTIMI,#OPTIMI,' \
	    ${WRKSRC}/speech_tools/config/compilers/gcc*.mak
.endfor

do-install:
	${MKDIR} ${FHOME}/lib/voices/english/
	${MKDIR} ${FHOME}/lib/voices/spanish/
	${MKDIR} ${FHOME}/lib/dicts
	${CHMOD} -R u+w,a+r,og-w ${FESTIVAL}/lib
	${FIND} ${FESTIVAL}/lib -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	cd ${FESTIVAL} && ${CP} -pPR lib examples ${FHOME}
	${RM} -rf ${FHOME}/lib/etc/Makefile ${FHOME}/lib/etc/*FreeBSD* \
	    ${FHOME}/lib/etc/*unknown
	${INSTALL_PROGRAM} ${FESTIVAL}/lib/etc/*/audsp ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/festival ${PREFIX}/libexec/festival.naked
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/festival_client ${PREFIX}/libexec/festival_client.naked
	for n in festival.sh festival_client.sh sitevars.scm; \
	do {\
	  ${SED} "s%@PKG_FESTIVAL_LOCATION@%${FHOME}%; \
	       s%@PKG_PREFIX@%${PREFIX}%" <${FILESDIR}/$$n > ${WRKDIR}/$$n ;} \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/festival.sh ${PREFIX}/bin/festival
	${INSTALL_SCRIPT} ${WRKDIR}/festival_client.sh ${PREFIX}/bin/festival_client
	${INSTALL_DATA} ${WRKDIR}/sitevars.scm ${FHOME}/lib/sitevars.scm
	${INSTALL_MAN} ${FESTIVAL}/doc/festival.1 ${PREFIX}/man/man1/festival.1
	${INSTALL_MAN} ${FESTIVAL}/doc/festival_client.1 ${PREFIX}/man/man1/festival_client.1
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
