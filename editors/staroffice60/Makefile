# New ports collection makefile for: StarOffice 6.0
# Date created:		03 October 2001
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	staroffice
PORTVERSION=	6.0
CATEGORIES=	editors linux
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.teleport.ch/FreeBSD/patches/
MASTER_SITE_SUBDIR=	obrien
DISTNAME=	so-6_0-beta-bin-linux-en.bin
DISTFILES=	so60dat-20011016.tar.bz2
EXTRACT_SUFX=
EXTRACT_ONLY=	so60dat-20011016.tar.bz2

MAINTAINER=	mbr@FreeBSD.org

FETCH_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libXrender.so.1.0:${PORTSDIR}/emulators/linux_base-7
BUILD_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libXrender.so.1.0:${PORTSDIR}/emulators/linux_base-7

BROKEN=		"SUN beta program for 6.0 has been closed. Distfile is not available anymore"
USE_BZIP2=	yes
ONLY_FOR_ARCHS=	i386
NO_CDROM=	'Must be downloaded direct from Sun via www interface'
IS_INTERACTIVE=	yes
NO_BUILD=	yes
SOVERSION=	${PORTNAME}${PORTVERSION}
KDEHOME=	.kde
WRKSRC=		${WRKDIR}/${SOVERSION}
TMPDIR=		${WRKDIR}/tmp
LD_PATH=	${TMPDIR}:${WRKSRC}:${LINUXBASE}/lib:${LINUXBASE}/usr/lib
INSTDB.INS=	${PREFIX}/${SOVERSION}/program/instdb.ins
OPENCONFIG=	${PREFIX}/${SOVERSION}/share/config/registry/cache/instance/org/openoffice

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
.if ${SIZE} < 400000
	@${ECHO}
	@${ECHO} There is only ${SIZE}K free disk space in
	@${ECHO} ${WRKDIRPREFIX}. To unpack Staroffice needs
	@${ECHO} at least 400000K free diskspace.
	@${FALSE}
.endif
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE="Please manually download ${DISTNAME}${EXTRACT_SUFX} from http://www.sun.com/staroffice.  Put ${DISTNAME}${EXTRACT_SUFX} into the directory ${DISTDIR} and run make again."
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
	@${CHMOD} 755 ${WRKSRC}/${DISTNAME}
	@cd ${WRKSRC}
	@SAL_IGNOREXERRORS=1 ${WRKSRC}/${DISTNAME} -extract ${WRKSRC}
	@${RM} ${WRKSRC}/${DISTNAME}
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
	@${PERL} -pi.orig -e \
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
	@${LN} -fs ${LINUXBASE}/usr/X11R6/lib/libXrender.so.1.0 \
		${WRKDIR}/tmp/libXrender.so
.endif
	@${CAT} ${PKGMESSAGE}
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" LD_LIBRARY_PATH=${LD_PATH} \
		TEMP=${TMPDIR} ${LINUXBASE}/bin/sh -c '${WRKSRC}/setup -net'
	@if [ -f ${PREFIX}/${SOVERSION}/program/setup ]; then \
		${ECHO} ; \
		${ECHO} Ignore the error-message. StarOffice6.0 has been installed ; \
		${ECHO} successfully on your system. ; \
		${ECHO} ; \
	else \
		${ECHO} ; \
		${ECHO} An error occured during StarOffice6.0 install. Please send a mail with debug-output and ; \
		${ECHO} some information about your FreeBSD-environment to mb@imp.ch. Thanks. ; \
		${ECHO} ; \
		${FALSE} ; \
	fi
	@${MKDIR} -p ${PREFIX}/${SOVERSION}/share/config/registry/cache/instance/org/openoffice
	@${MKDIR} ${OPENCONFIG}/Office
	@${MKDIR} ${OPENCONFIG}/ucb
.for f in Calc.dat Chart.dat Common.dat DataAccess.dat Draw.dat Impress.dat \
    Java.dat Labels.dat Linguistic.dat Math.dat SFX.dat TypeDetection.dat \
    Views.dat Writer.dat WriterWeb.dat
	@${INSTALL_DATA} ${WRKDIR}/Office/${f} ${OPENCONFIG}/Office
.endfor
.for f in Configuration.dat Hierarchy.dat Store.dat
	@${INSTALL_DATA} ${WRKDIR}/ucb/${f} ${OPENCONFIG}/ucb
.endfor
	@${INSTALL_DATA} ${WRKDIR}/Inet.dat ${OPENCONFIG}
.for f in Setup.dat UserProfile.dat
	@${INSTALL_DATA} ${WRKDIR}/${f} ${OPENCONFIG}
.endfor
.endif

post-install:
	@${MV} ${INSTDB.INS} ${INSTDB.INS}.orig
	@${SED} -e 's%DefaultDestPath = "${PREFIX}/staroffice%DefaultDestPath = "staroffice%' \
	    ${INSTDB.INS}.orig > ${INSTDB.INS}
	@${INSTALL_SCRIPT} ${PREFIX}/${SOVERSION}/program/soffice \
		${PREFIX}/${SOVERSION}/program/spadmin
.if !exists(${LINUXBASE}/usr/X11R6/lib/libXrender.so)
	@${LN} -fs ${LINUXBASE}/usr/X11R6/lib/libXrender.so.1.0 ${PREFIX}/${SOVERSION}/program/libXrender.so
.endif

install-user:
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" ${LINUXBASE}/bin/sh -c \
		${PREFIX}/${SOVERSION}/program/setup

.include <bsd.port.post.mk>
