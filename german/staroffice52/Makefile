# New ports collection makefile for: StarOffice 5.2 german
# Date created:		22 August 2000
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	staroffice
PORTVERSION=	5.2
CATEGORIES=	editors linux
DISTNAME=	so-5_2-ga-bin-linux-de.bin
DISTFILES=	soa-5_2-ga-bin-linux-de.bin so-5_2-ga-bin-linux-de.bin
EXTRACT_ONLY=

MAINTAINER=	mb@imp.ch

RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386
NO_CDROM=	'Sie muessen StarOffice manuell via WWW-Interface herunterladen.'
IS_INTERACTIVE=	yes
NO_BUILD=	yes
DIST_SUBDIR=	staroffice52
WRKSRC=		${WRKDIR}/office52
TMPDIR=		${WRKDIR}/tmp

.include <bsd.port.pre.mk>

#
# Staroffice benötigt einen System-Patch der erst
# in FreeBSD 4.1 verfügbar ist. Bitte bringen Sie ihr
# System auf den neuesten Stand.
#
.if ${OSVERSION} < 410000
BROKEN= YES
.endif

.if defined(WITH_CDROM)
IGNORE= "Bitte mounten Sie die Sun StarOffice 5.2 CDROM nach /cdrom and starten Sie make erneut."
.else	# FTP/web download
.if !exists(${_DISTDIR}/${DISTNAME})
IGNORE="Bitte laden Sie ${DISTNAME} manuell von http://www.sun.com/staroffice herunter. Kopieren Sie ${DISTNAME} in das Verzeichnis ${_DISTDIR} und starten Sie make erneut.  Wenn Sie die StarOffice 5.2 CDROM besitzen, koennen Sie auch 'make WITH_CDROM=yes' ausfuehren."
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
	@${WRKSRC}/${DISTNAME} -extract ${WRKSRC}
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
.if exists(/compat/linux/usr/local)
	@${LN} -fs /compat/linux/usr/local/office52 ${PREFIX}/office52
.endif
	@${CAT} ${PKGDIR}/MESSAGE
	@-TEMP=${TMPDIR} /compat/linux/bin/sh -c '${WRKSRC}/setup /net'
	@ ${ECHO}
	@ ${ECHO} Ignorieren Sie die Fehlermeldung. StarOffice5.2 wurde erfolgreich
	@ ${ECHO} auf Ihrem System installiert.
	@ ${ECHO}
.endif

post-install:
	@${PATCH} -s ${PREFIX}/office52/program/setup ${FILESDIR}/setup.patch
	@${PATCH} -s ${PREFIX}/office52/program/soffice ${FILESDIR}/soffice.patch

install-user:
	${PREFIX}/office52/program/setup

.include <bsd.port.post.mk>
