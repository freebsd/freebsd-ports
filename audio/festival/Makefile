# New ports collection makefile for:	festival
# Date created:        			2000-06-11
# Whom:					Trevor Johnson
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.11 1999/12/28 04:19:58 wiz Exp $
# $FreeBSD$
#

PORTNAME=	festival
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL}
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz \
		speech_tools-1.2.1.tar.gz

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Multi-lingual speech synthesis system

LIB_DEPENDS=	audio.2:${PORTSDIR}/audio/nas \
		esd.2:${PORTSDIR}/audio/esound

DIST_SUBDIR=	festival

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-aa

FESTIVAL_ARCH=	${MACHINE_ARCH:S/i386/ix86/}
USE_GCC=	2.95

WRKSRC=		${WRKDIR}

USE_GMAKE=	yes

SPEECHTOOLS=	${WRKSRC}/speech_tools
FESTIVAL=	${WRKSRC}/festival

FHOME=		${PREFIX}/share/festival

MAKE_ENV+=	PKG_EST_HOME=${SPEECHTOOLS} \
		EST_HOME=${SPEECHTOOLS} \
		PKG_FESTIVAL_BUILD_HOME=${FESTIVAL} \
		PKG_FESTIVAL_HOME=${FHOME} \
		PKG_COMPILER="${CC}" \
		PKG_X11BASE=${X11BASE} \
		PKG_PREFIX=${PREFIX} \
		EGCS_CC="${CC}" \
		EGCS_CXX="${CXX}" \
		GCC28_CC="${CC}" \
		GCC28_CXX="${CXX}" \
		GCC27_CC="${CC}" \
		GCC27_CXX="${CXX}" \
		GCC26_CC="${CC}" \
		GCC26_CXX="${CXX}" \
		CC="${CC}" \
		CXX="${CXX}"

MAN1=		festival.1 festival_client.1

pre-patch:
	${CP} ${SPEECHTOOLS}/config/config-dist ${SPEECHTOOLS}/config/config &&\
		${CHMOD} u+w ${SPEECHTOOLS}/config/config
	${CP} ${FESTIVAL}/config/config-dist ${FESTIVAL}/config/config && \
		${CHMOD} u+w ${FESTIVAL}/config/config

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} >= 500113
.for ii in compilers/gcc27.mak config config-dist
	@${MV} ${SPEECHTOOLS}/config/${ii} ${SPEECHTOOLS}/config/${ii}.orig
	@${SED} -e "s:= gcc:= gcc295:g" < ${SPEECHTOOLS}/config/${ii}.orig \
		> ${SPEECHTOOLS}/config/${ii}
.endfor
.endif
	@${CP} ${FILESDIR}/top-Makefile ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/FreeBSD.mak ${SPEECHTOOLS}/config/systems/FreeBSD.mak
.for i in 4 5
	@${LN} -fs ${SPEECHTOOLS}/config/systems/ix86_FreeBSD3.3.mak \
		${SPEECHTOOLS}/config/systems/${FESTIVAL_ARCH}_FreeBSD3.${i}.mak
.endfor
.for ii in 4 5
.for jj in 1 2 3 4 5 6 7 8 9 10 11
	@${LN} -fs ${SPEECHTOOLS}/config/systems/ix86_FreeBSD4.0.mak \
	${SPEECHTOOLS}/config/systems/${FESTIVAL_ARCH}_FreeBSD${ii}.${jj}.mak
.endfor
.endfor

do-install:
	${MKDIR} ${FHOME}/lib/voices/english/
	${MKDIR} ${FHOME}/lib/voices/spanish/
	${MKDIR} ${FHOME}/lib/dicts
	${CHMOD} -R u+w,a+r,og-w ${FESTIVAL}/lib
	${FIND} ${FESTIVAL}/lib -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	cd ${FESTIVAL} && ${CP} -pPR lib examples ${FHOME}
	${RM} -rf ${FHOME}/lib/etc/*FreeBSD*
	${INSTALL_PROGRAM} ${FESTIVAL}/lib/etc/*FreeBSD*/audsp ${PREFIX}/libexec
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

.include <bsd.port.post.mk>
