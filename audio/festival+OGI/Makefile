# New ports collection makefile for:	festival+OGI
# Date created:        			2003-11-05
# Whom:					trevor
# based on pkgsrc/audio/festival from NetBSD
#
# $NetBSD: Makefile,v 1.27 2003/10/06 21:40:17 jmc Exp $
# $FreeBSD$
#

PORTNAME=	festival+OGI
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_NETBSD}
DISTFILES=	festival-${PORTVERSION}.tar.gz \
		speech_tools-1.2.1.tar.gz \
		OGIresLPC-2.0.9.tar.gz

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	OGIfestpatch-1.4.1.2.tar.gz

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Text-to-speech system with OGI residual LPC synthesizer

LIB_DEPENDS=	audio.2:${PORTSDIR}/audio/nas \
		esd.2:${PORTSDIR}/audio/esound

BROKEN=		Incorrect pkg-plist
DEPRECATED=	"${BROKEN}"
EXPIRATION_DATE=2005-09-22

CONFLICTS=	festival-*
DIST_SUBDIR=	festival

RESTRICTED=	no-commercial-use

FESTIVAL=	${WRKSRC}/festival
FESTIVAL_ARCH=	${MACHINE_ARCH:S/i386/ix86/}
FHOME=		${PREFIX}/share/festival
MAKE_ENV+=	PKG_EST_HOME=${SPEECHTOOLS} \
		EST_HOME=${SPEECHTOOLS} \
		PKG_FESTIVAL_BUILD_HOME=${FESTIVAL} \
		PKG_FESTIVAL_HOME=${FHOME} \
		PKG_COMPILER="${CC}" \
		PKG_X11BASE=${X11BASE} \
		PKG_PREFIX=${PREFIX} \
		GCC27_CC="${CC}" \
		GCC27_CXX="${CXX}" \
		CC="${CC}" \
		CXX="${CXX}"
MAN1=		festival.1 festival_client.1
USE_GCC=	2.95
USE_GMAKE=	yes
SPEECHTOOLS=	${WRKSRC}/speech_tools
WRKSRC=		${WRKDIR}

pre-everything::
	@${ECHO_CMD} "* WARNING:  the source code for this port has not   *"
	@${ECHO_CMD} "* been properly reviewed by the FreeBSD maintainer. *"
	@${ECHO_CMD} "* Waiting ten seconds (control-C cancels build).    *"
	@sleep 10

post-extract:
	@${TAR} -C ${WRKSRC} -xzf \
		${DISTDIR}/${DIST_SUBDIR}/OGIfestpatch-1.4.1.2.tar.gz

pre-patch:
	${CP} ${FESTIVAL}/config/config-dist ${FESTIVAL}/config/config
	${CP} ${SPEECHTOOLS}/config/config-dist ${SPEECHTOOLS}/config/config
	${CHMOD} u+w ${FESTIVAL}/config/config ${SPEECHTOOLS}/config/config

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} > 500112
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
	${MKDIR} ${FHOME}/lib/voices/english/ ${FHOME}/lib/voices/italian/ \
		${FHOME}/lib/voices/spanish/ ${FHOME}/lib/dicts
	${CHMOD} -R u+w,a+r,og-w ${FESTIVAL}/lib
	${FIND} ${FESTIVAL}/lib -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	cd ${FESTIVAL} && ${CP} -pPR lib examples ${FHOME}
	${RM} -rf ${FHOME}/lib/etc/*FreeBSD*
	${INSTALL_PROGRAM} ${FESTIVAL}/lib/etc/*FreeBSD*/audsp ${PREFIX}/libexec
.for ii in festival festival_client
	${INSTALL_PROGRAM} ${FESTIVAL}/src/main/${ii} \
		${PREFIX}/libexec/${ii}.naked
.endfor
.for ii in festival.sh festival_client.sh sitevars.scm
	${SED} "s%@PKG_FESTIVAL_LOCATION@%${FHOME}%; \
		s%@PKG_PREFIX@%${PREFIX}%" <${FILESDIR}/${ii} > ${WRKDIR}/${ii}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/festival.sh ${PREFIX}/bin/festival
	${INSTALL_SCRIPT} ${WRKDIR}/festival_client.sh \
		${PREFIX}/bin/festival_client
	${INSTALL_DATA} ${WRKDIR}/sitevars.scm ${FHOME}/lib/sitevars.scm
.for ii in ${MAN1}
	${INSTALL_MAN} ${FESTIVAL}/doc/${ii} ${PREFIX}/man/man1/
.endfor

.include <bsd.port.post.mk>
