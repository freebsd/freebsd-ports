# New ports collection makefile for:	festival
# Date created:        			2000-06-11
# Whom:					Trevor Johnson <trevor@jpj.net>
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.11 1999/12/28 04:19:58 wiz Exp $
# $FreeBSD$
#

PORTNAME=	festival
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/festival/cstr/festival/${PORTVERSION}/ \
		ftp://ftp.leb.net/pub/blinux/${SUB} \
		ftp://ftp.mayn.de/pub/linux/BLinux/${SUB} \
		ftp://ftp.tuwien.ac.at/opsys/linux/blinux/${SUB}
SUB=		festival/mirror.festival_home/${PORTVERSION}/
.if defined (WITH_OGI)
MASTER_SITES+=	${PATCH_SITES}
PATCH_SITES=	ftp://ftp.leb.net/pub/blinux/festival/mirror.ogi-synth_home/ \
		ftp://ftp.mayn.de/pub/linux/BLinux/festival/mirror.ogi-synth_home/ \
		ftp://cslu.cse.ogi.edu/pub/tts/
.endif
DISTFILES=	${DISTNAME}.tar.gz \
		speech_tools-1.2.1.tar.gz
.if defined (WITH_OGI)
DISTFILES+=	OGIresLPC-2.0.4.tar.gz
.endif

.if defined (WITH_OGI)
PATCHFILES=	OGIfestpatch-${PORTVERSION}.tar.gz
.endif

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	audio.2:${PORTSDIR}/audio/nas \
		esd.2:${PORTSDIR}/audio/esound

DIST_SUBDIR=	festival

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-aa
.if defined (WITH_OGI)
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-aa-ogi
RESTRICTED=	no-commercial-use
.endif

.if defined (WITH_OGI)
PLIST=		${WRKDIR}/pkg-plist
.endif

WRKSRC=		${WRKDIR}

USE_GMAKE=	yes
USE_NEWGCC=	yes

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

.if defined (WITH_OGI)
post-extract:
	@${GUNZIP_CMD} -dc ${DISTDIR}/${DIST_SUBDIR}/OGIfestpatch-${PORTVERSION}.tar.gz \
	| ${TAR} -C ${WRKSRC} -xf -
.endif

.if !defined(WITH_OGI)
pre-fetch:
	@${ECHO}
	@${ECHO_MSG} "********************************************************"
	@${ECHO_MSG} "* To build this port with the OGI enhancements, define *"
	@${ECHO_MSG} "* \"WITH_OGI\" and restart the build.  The license for *"
	@${ECHO_MSG} "* the OGI materials prohibits commercial use, but they *"
	@${ECHO_MSG} "* are required by some of the voices.                  *"
	@${ECHO_MSG} "********************************************************"
	@${ECHO}
.endif

pre-patch:
	${CP} ${SPEECHTOOLS}/config/config-dist ${SPEECHTOOLS}/config/config && \
		${CHMOD} u+w ${SPEECHTOOLS}/config/config
	${CP} ${FESTIVAL}/config/config-dist ${FESTIVAL}/config/config && \
		${CHMOD} u+w ${FESTIVAL}/config/config

post-patch:
	${CP} ${FILESDIR}/top-Makefile ${WRKSRC}/Makefile
	${CP} ${FILESDIR}/FreeBSD.mak ${SPEECHTOOLS}/config/systems/FreeBSD.mak
.for arch in alpha ix86
.for i in 4 5
	${LN} -fs ${SPEECHTOOLS}/config/systems/ix86_FreeBSD3.3.mak \
		${SPEECHTOOLS}/config/systems/${arch}_FreeBSD3.${i}.mak
.endfor
.endfor
.for arch in alpha ix86
.for i in 1 2 3 4 5 6 7 8 9
	${LN} -fs ${SPEECHTOOLS}/config/systems/ix86_FreeBSD4.0.mak \
		${SPEECHTOOLS}/config/systems/${arch}_FreeBSD4.${i}.mak
.endfor
.endfor
.for arch in alpha ix86
	${CP} ${SPEECHTOOLS}/config/systems/ix86_FreeBSD4.0.mak \
		${SPEECHTOOLS}/config/systems/${arch}_FreeBSD5.0.mak
.endfor

pre-install:
.if defined (WITH_OGI)
	${CAT} ${PKGDIR}/pkg-plist-ogi ${PKGDIR}/pkg-plist > ${PLIST}
.endif

do-install:
	${MKDIR} ${FHOME}/lib/voices/english/
	${MKDIR}  ${FHOME}/lib/voices/spanish/
	${MKDIR} ${FHOME}/lib/dicts
	${CHMOD} -R u+w,a+r,og-w ${FESTIVAL}/lib
	find ${FESTIVAL}/lib -type d -print0| xargs -0 ${CHMOD} 755
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

.include <bsd.port.mk>
