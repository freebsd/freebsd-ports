# New ports collection makefile for: StarOffice 5.2
# Date created:		22 August 2000
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	staroffice
PORTVERSION=	5.2
CATEGORIES=	editors linux
MASTER_SITES=	ftp://ftp.inf.utfsm.cl/pub/UTFSM/StarOffice_5.2/ \
		ftp://ftp.snerpa.is/pub/linux/ \
		ftp://ftp.osb.hu/pub/mirrors/staroffice/linux/ \
		ftp://ftp.uni-linz.ac.at/pub/staroffice_5.2/ \
		ftp://sunsite.anu.edu.au/mnt/disk3/sun-info/sun-patches/ \
		ftp://ftp.labyrinth.net.au/.5/kk/linux/star_office/ \
		ftp://ftp.acs.oakland.edu/files/Linux/StarOffice/office52/ \
		ftp://ftp.ctio.noao.edu/linux/ \
		ftp://sunsite.cnlab-switch.ch/mirror/staroffice/english/ \
		ftp://ftp.linux.tucows.com/pub/Linuxberg/ \
		ftp://ftp.jcu.edu.au/pub/StarOffice/ \
		ftp://ftp.uakom.sk/pub/mirrors/StarOffice/ \
		ftp://ftp.linux.hr/pub/staroffice/5.2/ \
		ftp://ftp.isst.fhg.de/ISST/Sun/Staroffice/5.2/ \
		ftp://ftp.cityline.net/mirrors2/sun-patches-all/ \
		ftp://ftp.gtn.com/os/Sun/patches/ \
		ftp://ftp.jaist.ac.jp/.arc07/sun-info/sun-patches/ \
		ftp://ftp.hu-berlin.de/pub/mirrors/sunsolve.sun.com/pub/patches/ \
		ftp://sunsite.uio.no/pub/sun/sun-patches/ \
		ftp://ftp.sunet.se/pub7/security/vendor/sun/patches/
DISTNAME=	so-5_2-ga-bin-linux-en.bin
DISTFILES=	soa-5_2-ga-bin-linux-en.bin so-5_2-ga-bin-linux-en.bin 109939-02.tar.Z
EXTRACT_ONLY=	109939-02.tar.Z

MAINTAINER=	mb@imp.ch

FETCH_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386
NO_CDROM=	'Must be downloaded direct from Sun via www interface'
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
	@${ECHO} Staroffice depends on a scripting fix for
	@${ECHO} /usr/src/sys/i386/linux/linux_sysvec.c
	@${ECHO} \(revision 1.55.2.1 or higher\)
	@${ECHO}
	@${ECHO} Please upgrade to FreeBSD 4.1
	@${ECHO}
	@${FALSE}
.endif
.if defined(WITH_CDROM)
.if !exists(${CD_MOUNTPT}/linux/office52/setup)
	@${ECHO}
	@${ECHO} Please mount the Sun StarOffice 5.2 CDROM
	@${ECHO} onto ${CD_MOUNTPT} and run make again.
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
	@ ${ECHO} Can\'t open display:
	@ ${ECHO} Please check your DISPLAY variable.
	@ ${ECHO}
	@ ${FALSE}
.else
	@${MKDIR} ${WRKSRC}
	@${MKDIR} ${TMPDIR}
	@${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}
	@${CP} ${_DISTDIR}/soa-5_2-ga-bin-linux-en.bin ${WRKSRC}
	@${CHMOD} 755 ${WRKSRC}/${DISTNAME}
	@${CHMOD} 755 ${WRKSRC}/soa-5_2-ga-bin-linux-en.bin
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
	@ ${ECHO} Can\'t open display:
	@ ${ECHO} Please check your DISPLAY variable.
	@ ${ECHO}
	@ ${FALSE}
.else
.if exists(${LINUXBASE}/${PREFIX})
	@ ${LN} -fs ${LINUXBASE}/${PREFIX}/office52 ${PREFIX}/office52
.endif
	@${CAT} ${PKGMESSAGE}
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" TEMP=${TMPDIR} LD_LIBRARY_PATH=${LD_PATH} ${LINUXBASE}/bin/sh -c '${WRKSRC}/setup /net'
	@if [ -f ${PREFIX}/office52/program/setup ]; then \
		${ECHO} ; \
		${ECHO} Ignore the error-message. StarOffice5.2 has been installed ; \
		${ECHO} successfully on your system. ; \
		${ECHO} ; \
	else \
		${ECHO} ; \
		${ECHO} An error occured during StarOffice5.2 install. Please send a mail with debug-output and ; \
		${ECHO} some information about your FreeBSD-environment to mb@imp.ch. Thanks. ; \
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
