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
		ftp://sunsite.cnlab-switch.ch/mirror/staroffice/deutsch/ \
		ftp://ftp.schwabmuenchen.de/pub/Linux/Office/Star_Office/ \
		ftp://ftp.mayn.de/pub/unix/office/staroffice/ \
		ftp://ftp.isst.fhg.de/ISST/Sun/Staroffice/5.2/
DISTNAME=	so-5_2-ga-bin-linux-de.bin
DISTFILES=	soa-5_2-ga-bin-linux-de.bin so-5_2-ga-bin-linux-de.bin
EXTRACT_ONLY=

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
	@${ECHO} nach /cdrom and starten Sie make erneut.
	@${ECHO}
	@${FALSE}
.endif
.endif

.if defined(WITH_CDROM)
do-extract:
	@${MKDIR} ${WRKSRC}/office52
	@cd ${WRKSRC}/office52 && ${LN} -s ${CD_MOUNTPT}/linux/office52/* .
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
	@-SAL_IGNOREXERRORS=1 TEMP=${TMPDIR} LD_LIBRARY_PATH=${LD_PATH} ${LINUXBASE}/bin/sh -c '${WRKSRC}/setup /net'
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
	endif
.endif

post-install:
	@${PATCH} -s ${PREFIX}/office52/program/setup ${FILESDIR}/setup.patch
	@${PATCH} -s ${PREFIX}/office52/program/soffice ${FILESDIR}/soffice.patch

install-user:
	${PREFIX}/office52/program/setup

.include <bsd.port.post.mk>
