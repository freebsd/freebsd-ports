# New ports collection makefile for: StarOffice 5.2
# Date created:		22 August 2000
# Whom:                 Martin Blapp
# Translation:		Eric Masson
#
# $FreeBSD$
#

PORTNAME=	staroffice
PORTVERSION=	5.2
PORTREVISION=	3
CATEGORIES=	french editors linux
MASTER_SITES=	ftp://ftp.cem2.univ-montp2.fr/pub/linux/soft/StarOffice/ \
		ftp://sunsite.cnlab-switch.ch/mirror/staroffice/francais/ \
		ftp://ftp.be.embnet.org/pub/tools/StarOffice/Linux/ \
		ftp://ftp.medasys-digital-systems.fr/pub1/linux/staroffice/ \
		ftp://ftp.hu-berlin.de/pub/mirrors/sunsolve.sun.com/pub/patches/ \
		ftp://sunsite.anu.edu.au/mnt/disk3/sun-info/sun-patches/ \
		ftp://ftp.gtn.com/os/Sun/patches/
		
DISTNAME=	so-5_2-ga-bin-linux-fr.bin
.if defined(WITH_CDROM)
DISTFILES=	109939-03.tar.Z
.else
DISTFILES=	so-5_2-ga-bin-linux-fr.bin 109939-03.tar.Z
.if defined(WITH_ADABAS)
DISTFILES+=	soa-5_2-ga-bin-linux-fr.bin so-5_2-ga-bin-linux-fr.bin
.endif
.endif
EXTRACT_ONLY=	109939-03.tar.Z

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	Suite bureautique intégrée

FETCH_DEPENDS=	${LINUX_BASE_PORT}

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
NO_CDROM=	'Doit être téléchargé depuis le site web de Sun'
CD_MOUNTPT=	'/cdrom'
IS_INTERACTIVE=	yes
NO_BUILD=	yes
USE_PERL5_BUILD=yes
DIST_SUBDIR=	staroffice52
WRKSRC=		${WRKDIR}/office52
TMPDIR=		${WRKDIR}/tmp
LD_PATH=	${TMPDIR}:${WRKSRC}:${LINUXBASE}/linux/lib:${LINUXBASE}/usr/lib
INSTDB.INS=	${PREFIX}/office52/program/instdb.ins
SUNSOLVE=	${WRKDIR}/109939-03
ADABAS_DIST=	soa-5_2-ga-bin-linux-fr.bin
SIZE!=		/bin/df -k . | /usr/bin/tail -n 1 | /usr/bin/awk '{print $$4}'
LINPROCFS!=	/sbin/mount | /usr/bin/grep linprocfs | /usr/bin/awk '{print $1}'

.include <bsd.port.pre.mk>

pre-fetch:
.if ${LINPROCFS}
	@${ECHO}
	@${ECHO} Linprocfs est installeé: OUI
.else
	@${ECHO} -----------------------------------------------------------
	@${ECHO}
	@${ECHO} "Staroffice dépend sur linprocfs qui n'est pas activée"
	@${ECHO} "sur votre système. Veuiller lire le la page 'man' de"
	@${ECHO} "linprocfs(5) et ajouter la ligne suivante dans /etc/fstab:"
	@${ECHO}
	@${ECHO} "linproc /compat/linux/proc linprocfs rw 0 0"
	@${ECHO}
	@${ECHO} -----------------------------------------------------------
	@${FALSE}
.endif
.if ${OSVERSION} < 410000
	@${ECHO}
	@${ECHO} OS-VERSION ${OSVERSION}
	@${ECHO}
	@${ECHO} "Staroffice dépend d\'une modification du script"
	@${ECHO} "/usr/src/sys/i386/linux/linux_sysvec.c Celui-ci"
	@${ECHO} "Doit être au moins en révision 1.55.2.1."
	@${ECHO}
	@${ECHO} "Veuillez mettre à jour vers FreeBSD 4.1 SVP"
	@${ECHO}
	@${FALSE}
.endif
.if ${SIZE} < 250000
	@${ECHO}
	@${ECHO} "Le répertoire /usr/ports ne contient pas suffisament"
	@${ECHO} "d'espace libre. Staroffice a besoin au moins 250M"
	@${ECHO} "d'espace libre."
	@${ECHO}
	@${FALSE}
.endif
.if !defined(WITH_ADABAS)
	@${ECHO}
	@${ECHO} "Si vous voulez installer Staroffice avec support pour le système"
	@${ECHO} "de base de données ADABAS, terminez cette installation et"
	@${ECHO} "recommencez la avec l'option WITH_ADABAS=YES"
	@${ECHO}
.endif
.if defined(WITH_CDROM)
.if !exists(/cdrom/linux/office52/setup)
	@${ECHO}
	@${ECHO} "Montez le CDrom de Staroffice 5.2 dans le répertoire"
	@${ECHO} "${CD_MOUNTPT} et relancez l\'installation"
	@${ECHO}
	@${FALSE}
.endif
.endif

do-extract:
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@ ${ECHO}
	@ ${ECHO} Impossible d\'ouvrir le display X:
	@ ${ECHO} Vérifiez la variable DISPLAY
	@ ${ECHO}
	@ ${FALSE}
.else
	@${MKDIR} ${WRKSRC}
	@${MKDIR} ${TMPDIR}
.if defined(WITH_CDROM)
.if !exists(${CD_MOUNTPT}/linux/office52/setup)
.if defined(WITH_ADABAS)
	@cd ${WRKSRC} && ${LN} -s ${CD_MOUNTPT}/linux/adabas/adabas .
	@cd ${WRKSRC} && ${LN} -s ${CD_MOUNTPT}/linux/adabas/f_0000 .
	@cd ${WRKSRC} && ${LN} -s ${CD_MOUNTPT}/linux/adabas/f_0001 .
.endif
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${LN} -s ${CD_MOUNTPT}/linux/office52/* .
.endif
.else
	@${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}
	@${CHMOD} 755 ${WRKSRC}/${DISTNAME}
.if defined(WITH_ADABAS)
	@${CP} ${_DISTDIR}/${ADABAS_DIST} ${WRKSRC}
	@${CHMOD} 755 ${WRKSRC}/${ADABAS_DIST}
.endif
	@cd ${WRKSRC}
	@SAL_IGNOREXERRORS=1 ${WRKSRC}/${DISTNAME} -extract ${WRKSRC}
	@${RM} ${WRKSRC}/${DISTNAME}
.endif
	@cd ../../
	@for file in ${EXTRACT_ONLY}; do \
		if ! (cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		    ${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS}) ; \
		then \
			exit 1; \
		 fi \
	done
.endif

post-configure:
	@${PERL} -pi.orig -e 's|DefaultDestPath = "office52";|DefaultDestPath = "${PREFIX}/office52";|' ${WRKSRC}/setup.ins

do-install:
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@ ${ECHO}
	@ ${ECHO} Impossible d\'ouvrir le display X:
	@ ${ECHO} Vérifiez la variable DISPLAY
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
		${ECHO} été installé sur votre système. ; \
		${ECHO} ; \
	else \
		${ECHO} ; \
		${ECHO} Une erreur est survenue lors de l\'installation de StarOffice5.2. Envoyez un mail à mb@imp.ch ;\
		${ECHO} avec le debug et quelques informations sur votre environnement FreeBSD SVP. Merci. ; \
		${ECHO} ; \
		${FALSE} ; \
	fi
	@${ECHO_MSG} "===>   Application des correctifs sunsolve pour ${PKGNAME}"
	@for file in ${SUNSOLVE}/* ; do \
		${CP} -Rv $$file ${PREFIX}/office52/ ; \
	done
.endif

post-install:
	@${PATCH} -s ${PREFIX}/office52/program/setup ${FILESDIR}/setup.patch
	@${PATCH} -s ${PREFIX}/office52/program/soffice ${FILESDIR}/soffice.patch
	@${CP} ${INSTDB.INS} ${INSTDB.INS}.orig
	@${SED} -e 's%DefaultDestPath = "${PREFIX}/office52%DefaultDestPath = "office52%' \
	    < ${INSTDB.INS}.orig > ${INSTDB.INS}

install-user:
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" ${LINUXBASE}/bin/sh -c \
		${PREFIX}/office52/program/setup
# XXX: This is missing a "$BRANDELF} -t Linux <executables>".

.include <bsd.port.post.mk>
