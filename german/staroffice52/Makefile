# New ports collection makefile for: StarOffice 5.2 german
# Date created:		22 August 2000
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	staroffice
PORTVERSION=	5.2
CATEGORIES=	german editors linux
MASTER_SITES=	ftp://ftp.hu-berlin.de/pub/linux/staroffice/german/ \
		ftp://ftp.software-engineering.org/pub/mirrors/staroffice/5.2/ \
		ftp://ftp.uni-linz.ac.at/pub/staroffice_5.2/ \
		ftp://sunsite.anu.edu.au/mnt/disk3/sun-info/sun-patches/ \
		ftp://sunsite.cnlab-switch.ch/mirror/staroffice/deutsch/ \
		ftp://ftp.schwabmuenchen.de/pub/Linux/Office/Star_Office/ \
		ftp://ftp.mayn.de/pub/unix/office/staroffice/ \
		ftp://ftp.isst.fhg.de/ISST/Sun/Staroffice/5.2/ \
		ftp://ftp.cityline.net/mirrors2/sun-patches-all/ \
		ftp://ftp.gtn.com/os/Sun/patches/ \
		ftp://ftp.jaist.ac.jp/.arc07/sun-info/sun-patches/ \
		ftp://ftp.hu-berlin.de/pub/mirrors/sunsolve.sun.com/pub/patches/ \
		ftp://sunsite.uio.no/pub/sun/sun-patches/ \
		ftp://ftp.sunet.se/pub7/security/vendor/sun/patches/
DISTNAME=	so-5_2-ga-bin-linux-de.bin
DISTFILES=	soa-5_2-ga-bin-linux-de.bin so-5_2-ga-bin-linux-de.bin 109939-02.tar.Z
EXTRACT_ONLY=	109939-02.tar.Z

MAINTAINER=	mb@imp.ch

FETCH_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386
NO_CDROM=	'Sie muessen StarOffice manuell via WWW-Interface herunterladen.'
IS_INTERACTIVE=	yes
NO_BUILD=	yes
DIST_SUBDIR=	staroffice52
WRKSRC=		${WRKDIR}/office52
TMPDIR=		${WRKDIR}/tmp
LD_PATH=	${TMPDIR}:${WRKSRC}:${LINUXBASE}/lib:${LINUXBASE}/usr/lib
INSTDB.INS=	${PREFIX}/office52/program/instdb.ins
SUNSOLVE=	${WRKDIR}/109939-02

.include <bsd.port.pre.mk>

pre-fetch:
.if ${OSVERSION} < 410000
	@${ECHO}
	@${ECHO} OS-VERSION ${OSVERSION}
	@${ECHO}
	@${ECHO} Staroffice benötigt einen System-Patch der erst
	@${ECHO} seit FreeBSD 4.1 verfügbar ist. Bitte bringen Sie ihr
	@${ECHO} System auf den neuesten Stand.
	@${ECHO}
	@${FALSE}
.endif
.if defined(WITH_CDROM)
.if !exists(${CD_MOUNTPT}/linux/office52/setup)
	@${ECHO}
	@${ECHO} Bitte mounten Sie die Sun StarOffice 5.2 CDROM
	@${ECHO} nach ${CD_MOUNTPT} and starten Sie make erneut.
	@${ECHO}
	@${FALSE}
.endif
.endif

.if defined(WITH_CDROM)
do-extract: do-extract-cdrom
do-extract-cdrom:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${LN} -s ${CD_MOUNTPT}/linux/office52/* .
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
	@${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}
	@${CP} ${_DISTDIR}/soa-5_2-ga-bin-linux-de.bin ${WRKSRC}
	@${CHMOD} 755 ${WRKSRC}/${DISTNAME}
	@${CHMOD} 755 ${WRKSRC}/soa-5_2-ga-bin-linux-de.bin
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
		${ECHO} Während Ihrer StarOffice5.2 Installation ist ein Fehler aufgetreten. ; \
		${ECHO} Bitte schicken Sie ein Mail mit dem Fehlerbeschrieb an mb@imp.ch. Danke ; \
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
