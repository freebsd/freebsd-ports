# New ports collection makefile for: StarOffice 5.2 german
# Date created:		22 August 2000
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	staroffice
PORTVERSION=	5.2
PORTREVISION=	1
CATEGORIES=	german editors linux
MASTER_SITES=	ftp://ftp.hu-berlin.de/pub/linux/staroffice/german/ \
		ftp://sunsite.cnlab-switch.ch/mirror/staroffice/deutsch/ \
		ftp://ftp.isst.fhg.de/ISST/Sun/Staroffice/5.2/ \
		ftp://ftp.hu-berlin.de/pub/mirrors/sunsolve.sun.com/pub/patches/ \
		ftp://ftp.sunsite.auc.dk/disk2/sun-patches/ \
		ftp://sunsite.uio.no/pub/sun/sun-patches/ \
		ftp://ftp.sunet.se/pub7/security/vendor/sun/patches/
DISTNAME=	so-5_2-ga-bin-linux-de.bin
.if defined(WITH_CDROM)
DISTFILES=	109939-03.tar.Z
.else
DISTFILES=	so-5_2-ga-bin-linux-de.bin 109939-03.tar.Z
.if defined(WITH_ADABAS)
DISTFILES+=	soa-5_2-ga-bin-linux-de.bin
.endif
.endif
EXTRACT_ONLY=	109939-03.tar.Z

MAINTAINER=	mbr@FreeBSD.org

FETCH_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386
NO_CDROM=	'Sie muessen StarOffice manuell via WWW-Interface herunterladen.'
CD_MOUNTPT=	'/cdrom'
IS_INTERACTIVE=	yes
NO_BUILD=	yes
DIST_SUBDIR=	staroffice52
WRKSRC=		${WRKDIR}/office52
TMPDIR=		${WRKDIR}/tmp
LD_PATH=	${TMPDIR}:${WRKSRC}:${LINUXBASE}/lib:${LINUXBASE}/usr/lib
INSTDB.INS=	${PREFIX}/office52/program/instdb.ins
SUNSOLVE=	${WRKDIR}/109939-03
ADABAS_DIST=	soa-5_2-ga-bin-linux-de.bin
SIZE!=		/bin/df -k . | /usr/bin/tail -n 1 | /usr/bin/awk '{print $$4}'
LINPROCFS!=	/sbin/mount | /usr/bin/grep linprocfs | /usr/bin/awk '{print $1}'

.include <bsd.port.pre.mk>

pre-fetch:
.if ${LINPROCFS}
	@${ECHO}
	@${ECHO} Ist linprocfs installiert und gemounted: JA
.else
	@${ECHO} -----------------------------------------------------------
	@${ECHO}
	@${ECHO} Staroffice benoetigt ein gemountetes linprocfs, das auf
	@${ECHO} ihrem System nicht aktiviert ist. Bitte lesen Sie die
	@${ECHO} linprocfs\(5\) manpage und fuegen Sie folgende Line zu der
	@${ECHO} Datei /etc/fstab hinzu:
	@${ECHO}
	@${ECHO} linproc /compat/linux/proc linprocfs rw 0 0
	@${ECHO}
	@${ECHO} -----------------------------------------------------------
	@${FALSE}
.endif
.if ${OSVERSION} < 410000
	@${ECHO}
	@${ECHO} OS-VERSION ${OSVERSION}
	@${ECHO}
	@${ECHO} Staroffice benoetigt einen System-Patch der erst
	@${ECHO} seit FreeBSD 4.1 verfuegbar ist. Bitte bringen Sie ihr
	@${ECHO} System auf den neuesten Stand.
	@${ECHO}
	@${FALSE}
.endif
.if ${SIZE} < 250000
	@${ECHO}
	@${ECHO} In Ihrem Ports-Verzeichnis ist zuwenig Platz
	@${ECHO} enthalten. Staroffice benoetigt zum Entpacken
	@${ECHO} mindestens 250MB an freiem Speicherplatz.
	@${ECHO}
	@${FALSE}
.endif
.if !defined(WITH_ADABAS)
	@ ${ECHO}
	@ ${ECHO} Falls Sie Staroffice mit ADABAS Datenbank-Support installieren
	@ ${ECHO} moechten, brechen Sie die Installation ab und rufen Sie make
	@ ${ECHO} mit WITH_ADABAS=YES auf.
	@ ${ECHO}
.endif
.if defined(WITH_CDROM)
.if !exists(/cdrom/linux/office52/setup)
	@${ECHO}
	@${ECHO} Bitte mounten Sie die Sun StarOffice 5.2 CDROM
	@${ECHO} nach ${CD_MOUNTPT} and starten Sie make erneut.
	@${ECHO}
	@${FALSE}
.endif
.endif

do-extract:
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@ ${ECHO}
	@ ${ECHO} Die Variable DISPLAY ist nicht gesetzt. Setzen Sie entweder
	@ ${ECHO} das DISPLAY manuell oder rufen Sie make mit DISPLAY= und dem
	@ ${ECHO} entsprechenden DISPLAY als Parameter auf.
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
	@ ${ECHO} Die Variable DISPLAY ist nicht gesetzt. Setzen Sie entweder
	@ ${ECHO} das DISPLAY manuell oder rufen Sie make mit DISPLAY= und dem
	@ ${ECHO} entsprechenden DISPLAY als Parameter auf.
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
		${ECHO} Ignorieren Sie die Fehlermeldung. StarOffice5.2 wurde erfolgreich ; \
		${ECHO} auf Ihrem System installiert. ; \
		${ECHO} ; \
	else \
		${ECHO} ; \
		${ECHO} Waehrend Ihrer StarOffice5.2 Installation ist ein Fehler aufgetreten. ; \
		${ECHO} Bitte schicken Sie ein Mail mit dem Fehlerbeschrieb an mb@imp.ch. Danke ; \
		${ECHO} ; \
		${FALSE} ; \
	fi
	@${ECHO_MSG} "===>   Applying sunsolve patches for ${PKGNAME}"
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

.include <bsd.port.post.mk>
