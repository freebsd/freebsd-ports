# New ports collection makefile for: StarOffice 6.0
# Date created:		03 October 2001
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	staroffice
PORTVERSION=	6.0
CATEGORIES=	editors linux
MASTER_SITES=
DISTNAME=	so-6_0-beta-bin-linux-en.bin
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	mb@imp.ch

FETCH_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base
BUILD_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

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
	@${ECHO} There is too few free disk space in your port
	@${ECHO} directory. To unpack Staroffice needs
	@${ECHO} at least 400MB free diskspace.
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
	@${PERL} -pi.orig -e 's|DefaultDestPath = "staroffice%PRODUCTVERSION";|DefaultDestPath = "${PREFIX}/staroffice%PRODUCTVERSION";|' ${WRKSRC}/setup.ins

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
	@${CAT} ${PKGMESSAGE}
	@-SAL_IGNOREXERRORS=1 PATH="/bin:${PATH}" TEMP=${TMPDIR} LD_LIBRARY_PATH=${LD_PATH} ${LINUXBASE}/bin/sh -c '${WRKSRC}/setup -net'
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
.endif

post-install:
	@${CP} ${INSTDB.INS} ${INSTDB.INS}.orig
	@${SED} -e 's%DefaultDestPath = "${PREFIX}/staroffice%DefaultDestPath = "staroffice%' \
	    < ${INSTDB.INS}.orig > ${INSTDB.INS}
	@${CP} ${PREFIX}/${SOVERSION}/program/soffice ${PREFIX}/${SOVERSION}/program/spadmin
	@${CHMOD} 755 ${PREFIX}/${SOVERSION}/program/spadmin

install-user:
.if !exists(/home/mb/staroffice6.0/setup)
.if exists(${HOME}/.sversionrc)
	@${ECHO} "StarOffice 6.0=${HOME}/${SOVERSION}" >> "${HOME}/.sversionrc"
.else
	@${SED} -e 's|%%HOME%%|${HOME}|' < "${FILESDIR}/.sversionrc" > "${HOME}/.sversionrc"
.endif
	@${MKDIR} "${HOME}/${SOVERSION}/user/autotext"
	@${MKDIR} "${HOME}/${SOVERSION}/user/temp"
	@${MKDIR} "${HOME}/${SOVERSION}/user/autocorr"
	@${MKDIR} "${HOME}/${SOVERSION}/user/backup"
	@${MKDIR} "${HOME}/${SOVERSION}/user/basic"
	@${MKDIR} "${HOME}/${SOVERSION}/user/config/registry"
	@${MKDIR} "${HOME}/${SOVERSION}/user/config/registry/instance"
	@${MKDIR} "${HOME}/${SOVERSION}/user/config/registry/instance/org"
	@${MKDIR} "${HOME}/${SOVERSION}/user/config/registry/instance/org/openoffice"
	@${MKDIR} "${HOME}/${SOVERSION}/user/config/registry/instance/org/openoffice/Office"
	@${MKDIR} "${HOME}/${SOVERSION}/user/config/registry/instance/org/openoffice/ucb"
	@${MKDIR} "${HOME}/${SOVERSION}/user/template"
	@${MKDIR} "${HOME}/${SOVERSION}/user/database"
	@${MKDIR} "${HOME}/${SOVERSION}/user/database/biblio"
	@${MKDIR} "${HOME}/${SOVERSION}/user/gallery"
	@${MKDIR} "${HOME}/${SOVERSION}/user/wordbook"
	@${MKDIR} "${HOME}/${SOVERSION}/user/store"
	@${MKDIR} "${HOME}/${SOVERSION}/user/plugin"
	@${MKDIR} "${HOME}/${SOVERSION}/user/psprint"
	@${MKDIR} "${HOME}/${SOVERSION}/user/psprint/driver"
	@${MKDIR} "${HOME}/${SOVERSION}/user/psprint/fontmetric"
	@${MKDIR} "${HOME}/${SOVERSION}/share/autocorr"
	@${MKDIR} "${HOME}/${SOVERSION}/share/plugin"
	@${MKDIR} "${HOME}/${SOVERSION}/share/cde/information and setup"
	@${MKDIR} "${HOME}/${SOVERSION}/share/cde/auto pilots"
	@${MKDIR} "${HOME}/${SOVERSION}/share/cde/other"
	@${SED} -e 's|%%HOME%%|${HOME}|' -e 's|%%PREFIX%%|${PREFIX}|' \
		< "${FILESDIR}/Setup.xml" > "${HOME}/${SOVERSION}/user/config/registry/instance/org/openoffice/Setup.xml"
	@${SED} -e 's|%%HOME%%|${HOME}|' -e 's|%%PREFIX%%|${PREFIX}|' \
		< "${FILESDIR}/UserProfile.xml" > "${HOME}/${SOVERSION}/user/config/registry/instance/org/openoffice/UserProfile.xml"
	@${SED} -e 's|%%HOME%%|${HOME}|' -e 's|%%PREFIX%%|${PREFIX}|' \
		< "${FILESDIR}/instdb.ins.patch" > "${HOME}/${SOVERSION}/instdb.ins.patch"
	@${CP} ${INSTDB.INS} ${HOME}/${SOVERSION}/
	@${CP} "${FILESDIR}/javarc" ${HOME}/${SOVERSION}/user/config/
	@${PATCH} -s ${HOME}/${SOVERSION}/instdb.ins < ${HOME}/${SOVERSION}/instdb.ins.patch
	@${RM} "${HOME}/${SOVERSION}/instdb.ins.patch"
	@${RM} "${HOME}/${SOVERSION}/instdb.ins.orig"
	@${CP} "${FILESDIR}/sregistryrc" "${HOME}/${SOVERSION}/user/"
	@${CP} "${PREFIX}/${SOVERSION}/user/autotext/english/mytexts.bau" \
		"${HOME}/${SOVERSION}/user/autotext/mytexts.bau"
	@${CP} "${PREFIX}/${SOVERSION}/user/database/biblio/biblio.dbf" \
		"${HOME}/${SOVERSION}/user/database/biblio/biblio.dbf"
	@${CP} "${PREFIX}/${SOVERSION}/user/gallery/sg100.sdv" \
		"${HOME}/${SOVERSION}/user/gallery/sg100.sdv"
	@${CP} "${PREFIX}/${SOVERSION}/user/gallery/sg100.thm" \
		"${HOME}/${SOVERSION}/user/gallery/sg100.thm"
	@${CP} "${PREFIX}/${SOVERSION}/user/gallery/sg30.sdv" \
		"${HOME}/${SOVERSION}/user/gallery/sg30.sdv"
	@${CP} "${PREFIX}/${SOVERSION}/user/gallery/sg30.thm" \
		"${HOME}/${SOVERSION}/user/gallery/sg30.thm"
	@${CP} "${PREFIX}/${SOVERSION}/user/basic/dialogs.xli" \
		"${HOME}/${SOVERSION}/user/basic/dialogs.xli"
	@${CP} "${PREFIX}/${SOVERSION}/user/basic/script.xli" \
		"${HOME}/${SOVERSION}/user/basic/script.xli"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/arrowhd.soe" \
		"${HOME}/${SOVERSION}/user/config/arrowhd.soe"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/classic.sog" \
		"${HOME}/${SOVERSION}/user/config/classic.sog"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/hatching.soh" \
		"${HOME}/${SOVERSION}/user/config/hatching.soh"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/modern.sog" \
		"${HOME}/${SOVERSION}/user/config/modern.sog"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/palette.soc" \
		"${HOME}/${SOVERSION}/user/config/palette.soc"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/styles.sod" \
		"${HOME}/${SOVERSION}/user/config/styles.sod"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/autotbl.fmt" \
		"${HOME}/${SOVERSION}/user/config/autotbl.fmt"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/dbtitle.rdb" \
		"${HOME}/${SOVERSION}/user/config/dbtitle.rdb"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/cmyk.soc" \
		"${HOME}/${SOVERSION}/user/config/cmyk.soc"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/gallery.soc" \
		"${HOME}/${SOVERSION}/user/config/gallery.soc"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/html.soc" \
		"${HOME}/${SOVERSION}/user/config/html.soc"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/standard.sob" \
		"${HOME}/${SOVERSION}/user/config/standard.sob"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/standard.soc" \
		"${HOME}/${SOVERSION}/user/config/standard.soc"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/standard.sod" \
		"${HOME}/${SOVERSION}/user/config/standard.sod"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/standard.soe" \
		"${HOME}/${SOVERSION}/user/config/standard.soe"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/standard.sog" \
		"${HOME}/${SOVERSION}/user/config/standard.sog"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/standard.soh" \
		"${HOME}/${SOVERSION}/user/config/standard.soh"
	@${CP} "${PREFIX}/${SOVERSION}/user/config/web.soc" \
		"${HOME}/${SOVERSION}/user/config/web.soc"
	@${CP} "${PREFIX}/${SOVERSION}/LICENSE" \
		"${HOME}/${SOVERSION}/LICENSE"
	@${CP} "${PREFIX}/${SOVERSION}/README" \
		"${HOME}/${SOVERSION}/README"
	@${LN} -s "${PREFIX}/${SOVERSION}/program/setup" "${HOME}/${SOVERSION}/setup"
	@${LN} -s "${PREFIX}/${SOVERSION}/program/soffice" "${HOME}/${SOVERSION}/soffice"
	@${LN} -s "${PREFIX}/${SOVERSION}/program/spadmin" "${HOME}/${SOVERSION}/spadmin"
.if exists(${HOME}/.gnome/apps)
	@${MKDIR} "${HOME}/.gnome/apps/StarOffice 6.0"
	@${MKDIR} "${HOME}/.gnome/apps/StarOffice 6.0/information and setup"
	@${MKDIR} "${HOME}/.gnome/apps/StarOffice 6.0/other"
	@${MKDIR} "${HOME}/.gnome/apps/StarOffice 6.0/auto pilots"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/information and setup/.directory" \
		"${HOME}/.gnome/apps/StarOffice 6.0/information and setup/.directory"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/information and setup/setup.desktop" \
		"${HOME}/.gnome/apps/StarOffice 6.0/information and setup/setup.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/.order" \
		"${HOME}/.gnome/apps/StarOffice 6.0/.order"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/.directory" \
		"${HOME}/.gnome/apps/StarOffice 6.0/.directory"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/template.desktop" \
		"${HOME}/.gnome/apps/StarOffice 6.0/template.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/other/.directory" \
		"${HOME}/.gnome/apps/StarOffice 6.0/other/.directory"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/other/masterdoc.desktop" \
		"${HOME}/.gnome/apps/StarOffice 6.0/other/masterdoc.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/other/mathdoc.desktop" \
		"${HOME}/.gnome/apps/StarOffice 6.0/other/mathdoc.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/other/labels.desktop" \
		"${HOME}/.gnome/apps/StarOffice 6.0/other/labels.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/other/vcards.desktop" \
		"${HOME}/.gnome/apps/StarOffice 6.0/other/vcards.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/auto pilots/.directory" \
		"${HOME}/.gnome/apps/StarOffice 6.0/auto pilots/.directory"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/auto pilots/letter.desktop" \
		"${HOME}/.gnome/apps/StarOffice 6.0/auto pilots/letter.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/auto pilots/fax.desktop" \
		"${HOME}/.gnome/apps/StarOffice 6.0/auto pilots/fax.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/auto pilots/agenda.desktop" \
		"${HOME}/.gnome/apps/StarOffice 6.0/auto pilots/agenda.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/auto pilots/memo.desktop" \
		"${HOME}/.gnome/apps/StarOffice 6.0/auto pilots/memo.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/textdoc.desktop" \
		"${HOME}/.gnome/apps/StarOffice 6.0/textdoc.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/webdoc.desktop" \
		"${HOME}/.gnome/apps/StarOffice 6.0/webdoc.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/spreadsheet.desktop" \
		"${HOME}/.gnome/apps/StarOffice 6.0/spreadsheet.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/drawing.desktop" \
		"${HOME}/.gnome/apps/StarOffice 6.0/drawing.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/gnome/net/presentation.desktop" \
		"${HOME}/.gnome/apps/StarOffice 6.0/presentation.desktop"
.endif
.if exists(${HOME}/${KDEHOME})
	@${MKDIR} "${HOME}/${KDEHOME}/share/mimelnk"
	@${MKDIR} "${HOME}/${KDEHOME}/share/mimelnk/application"
	@${MKDIR} "${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0"
	@${MKDIR} "${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/other"
	@${MKDIR} "${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/auto pilots"
	@${MKDIR} "${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/information and setup"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/mimelnk/application/vnd.sun.xml.impress.desktop" \
		"${HOME}/${KDEHOME}/share/mimelnk/application/vnd.sun.xml.impress.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/mimelnk/application/vnd.stardivision.impress.desktop" \
		"${HOME}/${KDEHOME}/share/mimelnk/application/vnd.stardivision.impress.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/mimelnk/application/vnd.sun.xml.draw.desktop" \
		"${HOME}/${KDEHOME}/share/mimelnk/application/vnd.sun.xml.draw.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/mimelnk/application/vnd.stardivision.draw.desktop" \
		"${HOME}/${KDEHOME}/share/mimelnk/application/vnd.stardivision.draw.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/mimelnk/application/vnd.sun.xml.calc.desktop" \
		"${HOME}/${KDEHOME}/share/mimelnk/application/vnd.sun.xml.calc.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/mimelnk/application/vnd.stardivision.calc.desktop" \
		"${HOME}/${KDEHOME}/share/mimelnk/application/vnd.stardivision.calc.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/mimelnk/application/vnd.stardivision.chart.desktop" \
		"${HOME}/${KDEHOME}/share/mimelnk/application/vnd.stardivision.chart.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/mimelnk/application/vnd.sun.xml.writer.desktop"  \
		"${HOME}/${KDEHOME}/share/mimelnk/application/vnd.sun.xml.writer.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/mimelnk/application/vnd.sun.xml.writer.global.desktop" \
		"${HOME}/${KDEHOME}/share/mimelnk/application/vnd.sun.xml.writer.global.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/mimelnk/application/vnd.sun.xml.math.desktop" \
		"${HOME}/${KDEHOME}/share/mimelnk/application/vnd.sun.xml.math.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/mimelnk/application/vnd.stardivision.writer.desktop" \
		"${HOME}/${KDEHOME}/share/mimelnk/application/vnd.stardivision.writer.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/mimelnk/application/vnd.stardivision.writer-global.desktop" \
		"${HOME}/${KDEHOME}/share/mimelnk/application/vnd.stardivision.writer-global.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/mimelnk/application/vnd.stardivision.math.desktop" \
		"${HOME}/${KDEHOME}/share/mimelnk/application/vnd.stardivision.math.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/presentation.desktop" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/presentation.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/drawing.desktop" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/drawing.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/spreadsheet.desktop" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/spreadsheet.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/other/.directory" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/other/.directory"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/other/masterdoc.desktop" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/other/masterdoc.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/other/mathdoc.desktop" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/other/mathdoc.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/other/labels.desktop"  \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/other/labels.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/other/vcards.desktop" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/other/vcards.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/auto pilots/.directory" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/auto pilots/.directory"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/auto pilots/letter.desktop" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/auto pilots/letter.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/auto pilots/fax.desktop" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/auto pilots/fax.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/auto pilots/agenda.desktop" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/auto pilots/agenda.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/auto pilots/memo.desktop" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/auto pilots/memo.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/textdoc.desktop" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/textdoc.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/webdoc.desktop" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/webdoc.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/information and setup/.directory" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/information and setup/.directory "
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/information and setup/setup.desktop" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/information and setup/setup.desktop"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/.order" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/.order"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/.directory" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/.directory"
	@${CP} "${PREFIX}/${SOVERSION}/share/kde/net/applnk/StarOffice 6.0/template.desktop" \
		"${HOME}/${KDEHOME}/share/applnk/StarOffice 6.0/template.desktop"
.endif
.endif
.include <bsd.port.post.mk>
