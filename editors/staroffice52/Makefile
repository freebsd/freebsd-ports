# New ports collection makefile for: StarOffice 5.2
# Date created:		22 August 2000
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	staroffice
PORTVERSION=	5.2
PORTREVISION=	1
CATEGORIES=	editors linux
MASTER_SITES=	ftp://ftp.csua.berkeley.edu/pub/.1/ports/distfiles/staroffice52/ \
		ftp://sunsite.cnlab-switch.ch/mirror/staroffice/english/ \
		ftp://ftp.snerpa.is/pub/linux/staroffice/ \
		ftp://ftp.linux.tucows.com/pub/Linuxberg/ \
		ftp://ftp.linux.hr/pub/staroffice/5.2/ \
		ftp://ftp.sunsite.auc.dk/disk2/sun-patches/ \
		ftp://sunsite.uio.no/pub/sun/sun-patches/ \
		ftp://ftp.hu-berlin.de/pub/mirrors/sunsolve.sun.com/pub/patches/ \
		ftp://ftp.sunet.se/pub7/security/vendor/sun/patches/
DISTNAME=	so-5_2-ga-bin-linux-en.bin
.if defined(WITH_CDROM)
DISTFILES=	109939-03.tar.Z
.else
DISTFILES=	so-5_2-ga-bin-linux-en.bin 109939-03.tar.Z
.if defined(WITH_ADABAS)
DISTFILES+=	soa-5_2-ga-bin-linux-en.bin
.endif
.endif
EXTRACT_ONLY=	109939-03.tar.Z

MAINTAINER=	mbr@FreeBSD.org

FETCH_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386
NO_CDROM=	'Must be downloaded direct from Sun via www interface'
CD_MOUNTPT=	'/cdrom'
IS_INTERACTIVE=	yes
NO_BUILD=	yes
DIST_SUBDIR=	staroffice52
WRKSRC=		${WRKDIR}/office52
TMPDIR=		${WRKDIR}/tmp
LD_PATH=	${TMPDIR}:${WRKSRC}:${LINUXBASE}/lib:${LINUXBASE}/usr/lib
INSTDB.INS=	${PREFIX}/office52/program/instdb.ins
SUNSOLVE=	${WRKDIR}/109939-03
ADABAS_DIST=	soa-5_2-ga-bin-linux-en.bin
SIZE!=		/bin/df -k . | /usr/bin/tail -n 1 | /usr/bin/awk '{print $$4}'
LINPROCFS!=	/sbin/mount | /usr/bin/grep linprocfs | /usr/bin/awk '{print $1}'

.include <bsd.port.pre.mk>

pre-fetch:
.if ${LINPROCFS}
	@${ECHO}
	@${ECHO} Check if linprocfs is running: YES
.else
	@${ECHO} -----------------------------------------------------------
	@${ECHO}
	@${ECHO} Staroffice setup needs a running linprocfs, which is not
	@${ECHO} activated on your system. Please read the linprocfs\(5\)
	@${ECHO} manpage and add the following line to /etc/fstab:
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
	@${ECHO} Staroffice depends on a scripting fix for
	@${ECHO} /usr/src/sys/i386/linux/linux_sysvec.c
	@${ECHO} \(revision 1.55.2.1 or higher\)
	@${ECHO}
	@${ECHO} Please upgrade to FreeBSD 4.1
	@${ECHO}
	@${FALSE}
.endif
.if ${SIZE} < 250000
	@${ECHO}
	@${ECHO} There is too few free disk space in your port
	@${ECHO} directory. To unpack Staroffice needs
	@${ECHO} at least 250MB free diskspace.
	@${FALSE}
.endif
.if !defined(WITH_ADABAS)
	@ ${ECHO}
	@ ${ECHO} If you like to install staroffice with ADABAS database support,
	@ ${ECHO} cancel this installation now and start make again with
	@ ${ECHO} WITH_ADABAS=YES. 
	@ ${ECHO}
.endif
.if defined(WITH_CDROM)
.if !exists(/cdrom/linux/office52/setup)
	@${ECHO}
	@${ECHO} Please mount the Sun StarOffice 5.2 CDROM
	@${ECHO} onto ${CD_MOUNTPT} and run make again.
	@${ECHO}
	@${FALSE}
.endif
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
	@${RM} ${INSTDB.INS}.orig

install-user:
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" ${LINUXBASE}/bin/sh -c \
		${PREFIX}/office52/program/setup

.include <bsd.port.post.mk>
