# New ports collection makefile for: StarOffice 6.0
# Date created:		03 October 2001
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	staroffice
PORTVERSION=	6.0
PORTREVISION=	4
CATEGORIES=	editors linux
MASTER_SITES=	ftp://ftp.sunsite.auc.dk/disk6/sun-patches/:patch \
		ftp://ftp.math.ohio-state.edu/private/sun/.../:patch \
		ftp://ftp.uga.edu/pub/unix/sun/patches/:patch \
		ftp://ftp.cs.tu-berlin.de/pub/sun/sun-fixes/.../:patch
DISTNAME=	so-6_0-ga-bin-linux-en.bin
.if !defined(USE_CDROM)
DISTFILES=      so-6_0-ga-bin-linux-en.bin 112887-04.tar:patch
.endif
.if defined(WITH_ADABAS)
DISTFILES+=	soa-6_0-ga-bin-linux-en.bin
.endif

EXTRACT_ONLY=	112887-04.tar

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	Wordprocessor/dbase/spreadheet/drawing/chart

NO_LATEST_LINK=	yes
ONLY_FOR_ARCHS=	i386
NO_CDROM=	'Must be bought and downloaded direct from Sun via www interface'

USE_LINUX=	yes
USE_X_PREFIX=	yes
IS_INTERACTIVE=	yes
NO_BUILD=	yes
SOVERSION=	${PORTNAME}${PORTVERSION}
WRKSRC=		${WRKDIR}/${SOVERSION}
TMPDIR=		${WRKDIR}/tmp
LD_PATH=	${TMPDIR}:${WRKSRC}:${LINUXBASE}/lib:${LINUXBASE}/usr/lib
INSTDB.INS=	${PREFIX}/${SOVERSION}/program/instdb.ins
SUNSOLVE=	${WRKDIR}/112887-04
ADABAS_DIST=	soa-6_0-ga-bin-linux-en.bin

.include <bsd.port.pre.mk>

SIZE!=		/bin/df -k . | ${TAIL} -n 1 | ${AWK} '{print $$4}'
LINPROCFS!=	/sbin/mount | ${GREP} linprocfs | ${AWK} '{print $1}'

pre-fetch:
.if ${LINPROCFS}
	@${ECHO}
	@${ECHO} Check if linprocfs is running: YES
.else
	@${ECHO} Check if linprocfs is running: NO
	@${ECHO}
	@${ECHO} ERROR:
	@${ECHO}
	@${ECHO} Staroffice setup needs a running linprocfs. it seems
	@${ECHO} that procfs is not mounted on your system.  Please
	@${ECHO} read the linprocfs\(5\) manpage and ensure the
	@${ECHO} the following line is in /etc/fstab, and that the
	@${ECHO} linprocfs file system is mounted:
	@${ECHO}
	@${ECHO} linproc /compat/linux/proc linprocfs rw 0 0
	@${ECHO}
	@${FALSE}
.endif
.if !exists(${LINUXBASE}/etc/mtab)
	@${ECHO}
	@${ECHO} ERROR:
	@${ECHO}
	@${ECHO} The file ${LINUXBASE}/etc/mtab is missing.
	@${ECHO} Staroffice needs this file else some functions
	@${ECHO} are not working. You can create it with
	@${ECHO}
	@${ECHO} touch ${LINUXBASE}/etc/mtab
	@${ECHO}
	@${FALSE}
.else
	@${ECHO} Check if ${LINUXBASE}/etc/mtab exists: YES
.endif
.if ${OSVERSION} < 450000
	@${ECHO}
	@${ECHO} ERROR:
	@${ECHO}
	@${ECHO} OS-VERSION ${OSVERSION}
	@${ECHO}
	@${ECHO} Staroffice depends on a scripting fix for
	@${ECHO} /usr/src/sys/i386/linux/linux_sysvec.c
	@${ECHO}
	@${ECHO} Please upgrade to FreeBSD 4.5 or later.
	@${ECHO}
	@${FALSE}
.endif
.if ${SIZE} < 400000
	@${ECHO}
	@${ECHO} ERROR:
	@${ECHO}
	@${ECHO} There is only ${SIZE}K free disk space in
	@${ECHO} ${WRKDIRPREFIX}. To unpack Staroffice needs
	@${ECHO} at least 400000K free diskspace.
	@${FALSE}
.endif
.if !defined(WITH_ADABAS)
	@${ECHO}
	@${ECHO} If you like to install staroffice with ADABAS database support,
	@${ECHO} cancel this installation now and start make again with
	@${ECHO} WITH_ADABAS=YES.
	@${ECHO}
.endif
.if defined(USE_CDROM)
DLTEST=112887-04.tar
.else
.if exists(/cdrom/linux/office60/setup)
	@${ECHO}
	@${ECHO} It seems that you have a Sun StarOffice 6.0 CDROM
	@${ECHO} mounted on ${CD_MOUNTPT}.  If you wish to install from
	@${ECHO} this CD-ROM, please run 
	@${ECHO}
	@${ECHO}        make USE_CDROM=YES
	@${ECHO}
	@${ECHO} Otherwise please unmount the CD-ROM.
	@${ECHO}
	@${FALSE}
.endif
DLTEST=${DISTNAME}
.endif
.if !exists(${DISTDIR}/${DLTEST})
IGNORE="Please manually download ${DLTEST} from http://www.sun.com/staroffice.  Put ${DLTEST} into the directory ${DISTDIR} and run make again."
.endif

post-extract:
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@ ${ECHO}
	@ ${ECHO} Can\'t open display:
	@ ${ECHO} Please check your DISPLAY variable.
	@ ${ECHO}
	@ ${FALSE}
.else
	@${MKDIR} ${WRKSRC}
.if defined(USE_CDROM)
	@ln -sf /cdrom/linux/office60/* ${WRKSRC}
.else
	@${MKDIR} ${TMPDIR}
	@${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}
	@${CHMOD} 755 ${WRKSRC}/${DISTNAME}
	@cd ${WRKSRC}
	@SAL_IGNOREXERRORS=1 ${WRKSRC}/${DISTNAME} -extract ${WRKSRC}
	@${RM} ${WRKSRC}/${DISTNAME}
.endif
.if defined(WITH_ADABAS)
	@${CP} ${_DISTDIR}/${ADABAS_DIST} ${WRKSRC}
	@${CHMOD} 755 ${WRKSRC}/${ADABAS_DIST}
.endif
.endif

post-configure:
	@${SED} -i .orig -e \
	    's|DefaultDestPath = "staroffice%PRODUCTVERSION";|DefaultDestPath = "${PREFIX}/staroffice%PRODUCTVERSION";|' \
	    ${WRKSRC}/setup.ins

do-install:
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@ ${ECHO}
	@ ${ECHO} Can\'t open display:
	@ ${ECHO} Please check your DISPLAY variable.
	@ ${ECHO}
	@ ${FALSE}
.else
.if exists(${LINUXBASE}/${PREFIX})
	@${LN} -fs ${LINUXBASE}/${PREFIX}/${SOVERSION} ${PREFIX}/${SOVERSION}
.endif
.if !exists(${LINUXBASE}/usr/X11R6/lib/libXrender.so)
.if exists(${LINUXBASE}/usr/X11R6/lib/libXrender.so.1.0)
	@${LN} -fs ${LINUXBASE}/usr/X11R6/lib/libXrender.so.1.0 \
		${WRKDIR}/tmp/libXrender.so
.endif
.endif
	@${ECHO} ;
	@${ECHO_MSG} "===>   STEP 1: Main Setup ${PKGNAME}"
	@${ECHO} ;
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" LD_LIBRARY_PATH=${LD_PATH} \
		TEMP=${TMPDIR} ${LINUXBASE}/bin/sh -c '${WRKSRC}/setup /net'
	@if [ -f ${PREFIX}/${SOVERSION}/program/setup ]; then \
		${ECHO} ; \
		${ECHO} Ignore the error message. StarOffice6.0 has been installed ; \
		${ECHO} successfully on your system. ; \
		${ECHO} ; \
	else \
		${ECHO} ; \
		${ECHO} An error occured during StarOffice6.0 install. Please send a mail with debug-output and ; \
		${ECHO} some information about your FreeBSD-environment to mb@imp.ch. Thanks. ; \
		${ECHO} ; \
		${FALSE} ; \
	fi
	@${ECHO} ;
	@${ECHO_MSG} "===>   STEP 2: Choosing now a workstation installation for user root"
	@${ECHO} ;
	@${ECHO} This step is needed to be able to install the service pack. ;
	@${ECHO} ;
.if !exists(${LINUXBASE}/usr/X11R6/lib/libXrender.so)
	@${LN} -fs ${LINUXBASE}/usr/X11R6/lib/libXrender.so.1.0 ${PREFIX}/${SOVERSION}/program/libXrender.so
.endif
	@${SED} -i .orig -e 's%DefaultDestPath = "${PREFIX}/staroffice%DefaultDestPath = "staroffice%' \
	${INSTDB.INS}
.endif
.if defined(WITH_ADABAS)
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" LD_LIBRARY_PATH=${LD_PATH} \
		TEMP=${TMPDIR} ${LINUXBASE}/bin/sh -c '${WRKSRC}/${ADABAS_DIST}'
.endif
	@${ECHO} ;
	@${ECHO_MSG} "===>   STEP 3: Applying sunsolve patches for ${PKGNAME}"
	@${ECHO} ;
	@make install-patch
	@${CAT} ${PKGMESSAGE}

post-install:
	@${ECHO_MSG} "===>  Add wrapper scripts";
	@${SED} -e 's#%%PREFIX%%#${PREFIX}#g' < ${FILESDIR}/wrapper \
	   > ${WRKDIR}/staroffice6
	 @${INSTALL_SCRIPT} ${WRKDIR}/staroffice6 ${PREFIX}/bin/staroffice6
	@${LN} -fs ${PREFIX}/bin/staroffice6 ${PREFIX}/bin/staroffice-sagenda
	@${LN} -fs ${PREFIX}/bin/staroffice6 ${PREFIX}/bin/staroffice-scalc
	@${LN} -fs ${PREFIX}/bin/staroffice6 ${PREFIX}/bin/staroffice-sdraw
	@${LN} -fs ${PREFIX}/bin/staroffice6 ${PREFIX}/bin/staroffice-setup
	@${LN} -fs ${PREFIX}/bin/staroffice6 ${PREFIX}/bin/staroffice-sfax
	@${LN} -fs ${PREFIX}/bin/staroffice6 ${PREFIX}/bin/staroffice-simpress
	@${LN} -fs ${PREFIX}/bin/staroffice6 ${PREFIX}/bin/staroffice-spadmin
	@${LN} -fs ${PREFIX}/bin/staroffice6 ${PREFIX}/bin/staroffice-sweb
	@${LN} -fs ${PREFIX}/bin/staroffice6 ${PREFIX}/bin/staroffice-swriter
# XXX: This is missing a "${BRANDELF} -t Linux <executables>".
	@${ECHO} StarOffice6.0 has been installed successfully.  In order to use
	@${ECHO} it, execute ${PREFIX}/bin/staroffice6.
	@${ECHO} 

install-patch:
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" LD_LIBRARY_PATH=${LD_PATH} \
		TEMP=${TMPDIR} ${LINUXBASE}/bin/sh -c '${WRKSRC}/../112887-04/so-6_0-pp2-bin-linux.bin -patch:${PREFIX}/staroffice6.0'

install-update:
	@make extract
	@make install-patch

.include <bsd.port.post.mk>
