# New ports collection makefile for: StarOffice 5.2
# Date created:		22 August 2000
# Whom:                 Martin Blapp
# Translation:		Eric Masson
#
# $FreeBSD$
#

PORTNAME=	staroffice
PORTVERSION=	5.2
CATEGORIES=	french editors linux
MASTER_SITES=	ftp://sunsite.cnlab-switch.ch/mirror/staroffice/francais/ \
		ftp://ftp.math.u-bordeaux.fr/pub/StarOffice/Linux-Intel/ \
		ftp://ftp.be.embnet.org/pub/tools/StarOffice/Linux/ \
		ftp://ftp.medasys-digital-systems.fr/pub1/linux/staroffice/ \
		ftp://ftp.hu-berlin.de/pub/mirrors/sunsolve.sun.com/pub/patches/ \
		ftp://sunsite.anu.edu.au/mnt/disk3/sun-info/sun-patches/ \
		ftp://ftp.gtn.com/os/Sun/patches/
		
DISTNAME=	so-5_2-ga-bin-linux-fr.bin
DISTFILES=	so-5_2-ga-bin-linux-fr.bin 109939-02.tar.Z
.if defined(WITH_ADABAS)
DISTFILES+=	soa-5_2-ga-bin-linux-fr.bin so-5_2-ga-bin-linux-fr.bin
.endif
EXTRACT_ONLY=	109939-02.tar.Z

MAINTAINER=	mb@imp.ch

FETCH_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386
NO_CDROM=	'Doit etre telecharge depuis le site web de Sun'
IS_INTERACTIVE=	yes
NO_BUILD=	yes
DIST_SUBDIR=	staroffice52
WRKSRC=		${WRKDIR}/office52
TMPDIR=		${WRKDIR}/tmp
LD_PATH=	${TMPDIR}:${WRKSRC}:${LINUXBASE}/linux/lib:${LINUXBASE}/usr/lib
INSTDB.INS=	${PREFIX}/office52/program/instdb.ins
SUNSOLVE=	${WRKDIR}/109939-02

.include <bsd.port.pre.mk>

pre-fetch:
.if ${OSVERSION} < 410000
	@${ECHO}
	@${ECHO} OS-VERSION ${OSVERSION}
	@${ECHO}
	@${ECHO} Staroffice depend d\'une modification du script
	@${ECHO} /usr/src/sys/i386/linux/linux_sysvec.c Celui-ci
	@${ECHO} Doit etre au moins en revision 1.55.2.1.
	@${ECHO}
	@${ECHO} Veuillez mettre à jour vers FreeBSD 4.1 SVP
	@${ECHO}
	@${FALSE}
.endif
.if defined(WITH_CDROM)
.if !exists(${CD_MOUNTPT}/linux/office52/setup)
	@${ECHO}
	@${ECHO} Montez le CDrom de Staroffice 5.2 dans le repertoire
	@${ECHO} ${CD_MOUNTPT} et relancez l\'installation
	@${ECHO}
	@${FALSE}
.endif
.endif

.if defined(WITH_CDROM)
do-extract: do-extract-cdrom
do-extract-cdrom:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${LN} -s ${CD_MOUNTPT}/linux/office52/* .
.else

do-extract:
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@ ${ECHO}
	@ ${ECHO} Impossible d\'ouvrir le display X:
	@ ${ECHO} Verifiez la variable DISPLAY
	@ ${ECHO}
	@ ${FALSE}
.else
	@${MKDIR} ${WRKSRC}
	@${MKDIR} ${TMPDIR}
	@${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}
	@${CHMOD} 755 ${WRKSRC}/${DISTNAME}
.if defined(WITH_ADABAS)
	@${CP} ${_DISTDIR}/soa-5_2-ga-bin-linux-fr.bin ${WRKSRC}
	@${CHMOD} 755 ${WRKSRC}/soa-5_2-ga-bin-linux-fr.bin
.endif
	@cd ${WRKSRC}
	@SAL_IGNOREXERRORS=1 ${WRKSRC}/${DISTNAME} -extract ${WRKSRC}
	@cd ../../
	@for file in ${EXTRACT_ONLY}; do \
		if ! (cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		    ${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS}) ; \
		then \
			exit 1; \
		 fi \
	done
.endif
.endif

post-configure:
	@${PERL} -pi.orig -e 's|DefaultDestPath = "office52";|DefaultDestPath = "${PREFIX}/office52";|' ${WRKSRC}/setup.ins

do-install:
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@ ${ECHO}
	@ ${ECHO} Impossible d\'ouvrir le display X:
	@ ${ECHO} Verifiez la variable DISPLAY
	@ ${ECHO}
	@ ${FALSE}
.else
.if exists(${LINUXBASE}/${PREFIX})
	@${LN} -fs ${LINUXBASE}/${PREFIX}/office52 ${PREFIX}/office52
.endif
	@${CAT} ${PKGMESSAGE}
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" TEMP=${TMPDIR} LD_LIBRARY_PATH=${LD_PATH} ${LINUXBASE}/bin/sh -c '${WRKSRC}/setup /net'
	@if [ -f ${PREFIX}/office52/program/setup ]; then \
		${ECHO} ; \
		${ECHO} Ignorez le message d\'erreur. StarOffice5.2 a correctement ; \
		${ECHO} ete installe sur votre système. ; \
		${ECHO} ; \
	else \
		${ECHO} ; \
		${ECHO} Une erreur est survenue lors de l\'installation de StarOffice5.2. Envoyez un mail à mb@imp.ch ;\
		${ECHO} avec le debug et quelques informations sur votre environnement FreeBSD SVP. Merci. ; \
		${ECHO} ; \
		${FALSE} ; \
	fi
.if ! defined(WITH_CDROM)
	@${ECHO_MSG} "===>   Applying sunsolve patches for ${PKGNAME}"
	@for file in ${SUNSOLVE}/* ; do \
		${CP} -Rv $$file ${PREFIX}/office52/ ; \
	done
.endif
.endif

post-install:
	@${PATCH} -s ${PREFIX}/office52/program/setup ${FILESDIR}/setup.patch
	@${PATCH} -s ${PREFIX}/office52/program/soffice ${FILESDIR}/soffice.patch
	@${CP} ${INSTDB.INS} ${INSTDB.INS}.orig
	@${SED} -e 's%DefaultDestPath = "/usr/local/office52%DefaultDestPath = "office52%' \
	    < ${INSTDB.INS}.orig > ${INSTDB.INS}

install-user:
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" ${LINUXBASE}/bin/sh -c \
		${PREFIX}/office52/program/setup

.include <bsd.port.post.mk>
