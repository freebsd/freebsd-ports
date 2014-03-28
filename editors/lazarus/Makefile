# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	lazarus
PORTVERSION=	1.2
PORTREVISION?=	0
CATEGORIES=	editors devel
MASTER_SITES=	SF/${PORTNAME}/Lazarus%20Zip%20_%20GZip/Lazarus%20${PORTVERSION} \
		${MASTER_SITE_LOCAL:S|$|acm/freepascal/|}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/$/-0/}
DIST_SUBDIR=	freepascal

MAINTAINER?=	acm@FreeBSD.org
COMMENT?=	A portable Delphi-like IDE for the FreePascal compiler

BUILD_DEPENDS?=	#
RUN_DEPENDS?=	#

ONLY_FOR_ARCHS=	i386 amd64

USES=		gmake
USE_GMAKE=	yes
USE_GNOME=	#
USE_FPC?=	fcl-base fcl-db fcl-fpcunit fcl-image fcl-process fcl-registry \
		fcl-res fcl-xml iconvenc numlib pasjpeg x11
OPT?=		"-Sgic "

MAKE_ENV=	OPT=${OPT}
PLIST=		${WRKDIR}/pkg-plist
WRKSRC?=	${WRKDIR}/${PORTNAME}

.if !defined(PKGNAMESUFFIX)
OPTIONS_DEFINE=		GDB
OPTIONS_SINGLE=		LCL
OPTIONS_SINGLE_LCL=	GTK1 GTK2 QT4

GDB_DESC=		Install a newest version  of gdb
GTK1_DESC=		Use gtk12 interface
GTK2_DESC=		Use gtk20 interface
QT4_DESC=		Use qt4 interface

OPTIONS_DEFAULT=	GTK2 GDB
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
LAZARUS_ARCH=	i386
.elif ${ARCH} == "amd64"
LAZARUS_ARCH=	x86_64
.endif

BUILDNAME=	${LAZARUS_ARCH}-freebsd
LCL_UNITS_DIR=	${LOCALBASE}/share/lazarus/lcl/units/${BUILDNAME}

.if !defined(PKGNAMESUFFIX)
BUILD_DEPENDS+=	fpcres:${PORTSDIR}/lang/fpc-utils \
		${LCL_UNITS_DIR}/alllclunits.ppu:${PORTSDIR}/editors/lazarus-lcl-units \
		${LCL_UNITS_DIR}/nogui/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-nogui
RUN_DEPENDS+=	fpcres:${PORTSDIR}/lang/fpc-utils \
		${LCL_UNITS_DIR}/alllclunits.ppu:${PORTSDIR}/editors/lazarus-lcl-units \
		${LCL_UNITS_DIR}/nogui/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-nogui

USES+=	gettext iconv

MAN1=		lazarus-ide.1 lazbuild.1 startlazarus.1
SUB_FILES=	pkg-message
SUB_LIST+=	PORTSDIR="${PORTSDIR}"

.if ${PORT_OPTIONS:MGDB}
RUN_DEPENDS+=	gdb762:${PORTSDIR}/devel/gdb
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_FPC+=	gtk2
USE_GNOME=	gtk20 gdkpixbuf
LCL_PLATFORM=	gtk2
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-gtk2
RUN_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-gtk2
.endif

.if ${PORT_OPTIONS:MGTK1}
USE_FPC+=	gtk1
USE_GNOME=	gtk12 gdkpixbuf
LCL_PLATFORM=	gtk
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-gtk
RUN_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-gtk
.endif

.if ${PORT_OPTIONS:MQT4}
LIB_DEPENDS+=	Qt4Pas.5:${PORTSDIR}/x11-toolkits/qt4pas
LCL_PLATFORM=	qt
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-qt
RUN_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:${PORTSDIR}/editors/lazarus-lcl-qt
#OPT_EXTRA=	"-dUSE_QT_45"
.endif

post-extract:
	@${MKDIR} ${WRKDIR}/man1
	@${MV} ${WRKSRC}/install/man/man1/lazarus-ide.1 ${WRKDIR}/man1/
	@${MV} ${WRKSRC}/install/man/man1/lazbuild.1 ${WRKDIR}/man1/
	@${MV} ${WRKSRC}/install/man/man1/startlazarus.1 ${WRKDIR}/man1/
	@${MV} ${WRKSRC}/examples ${WRKDIR}/examples
	@${MV} ${WRKSRC}/docs ${WRKDIR}/docs

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' -e 's|%%DATADIR%%|${DATADIR}|g' \
			-e 's|tools: lcl|tools:|g' -e '2840d' -e '2842d' -e '2843d' -e '2844d' ${WRKSRC}/${MAKEFILE}

pre-build:
	@${LN} -s ${LOCALBASE}/share/${PORTNAME}/lcl/units ${WRKSRC}/lcl/units
	@${LN} -s ${LOCALBASE}/share/${PORTNAME}/components/ideintf/units ${WRKSRC}/components/ideintf/units
	@${LN} -s ${LOCALBASE}/share/${PORTNAME}/components/synedit/units ${WRKSRC}/components/synedit/units
	@${LN} -s ${LOCALBASE}/share/${PORTNAME}/components/lazcontrols/lib ${WRKSRC}/components/lazcontrols/lib

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} registration lazutils codetools bigide starter lazbuild LCL_PLATFORM=${LCL_PLATFORM}
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} tools LCL_PLATFORM=${LCL_PLATFORM}

post-build:
	@cd ${WRKSRC} && \
		${RM} -Rf COPYING* README* debian localize.bat test *.orig *.bak startlazarus.app \
			ide/Makefile*.orig ide/Makefile*.bak lcl/units components/ideintf/units \
				components/synedit/units components/lazcontrols/lib

pre-install:
	@${ECHO} "#!/bin/sh" > ${WRKDIR}/lazarus-wrapper
	@${ECHO} "cd ${DATADIR} || exit 1 " >> ${WRKDIR}/lazarus-wrapper
	@${ECHO} "exec ./startlazarus" >> ${WRKDIR}/lazarus-wrapper

	@${RM} -f ${PLIST}
	@${RM} -f ${WRKSRC}/lcl/units

.	for FILE in bin/lazarus bin/lazbuild
		@${ECHO_CMD} ${FILE} >> ${PLIST}
.	endfor

.if !defined(NOPORTDOCS)
	@${ECHO_CMD} "%%DATADIR%%/docs" >> ${PLIST}
	@cd ${WRKDIR}/docs && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DOCSDIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DOCSDIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DOCSDIR%%" >> ${PLIST}
.endif

.if !defined(NOPORTEXAMPLES)
	@${ECHO_CMD} "%%DATADIR%%/examples" >> ${PLIST}
	@cd ${WRKDIR}/examples && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%EXAMPLESDIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%EXAMPLESDIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%EXAMPLESDIR%%" >> ${PLIST}
.endif

	@cd ${WRKSRC} && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrmtry %%DATADIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry %%DATADIR%%" >> ${PLIST}

do-install:
.for DIRE in components converter debugger designer doceditor ide images install languages lazarus.app lcl \
	packager tools units
		@${MKDIR} ${DATADIR}/${DIRE}
		@cd ${WRKSRC}/${DIRE} && \
			${FIND} * -type d -exec ${MKDIR} "${DATADIR}/${DIRE}/{}" \; && \
				${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/${DIRE}/{}" \;
.endfor
	@${CHMOD} +x ${DATADIR}/tools/svn2revisioninc ${DATADIR}/tools/lazres ${DATADIR}/tools/lrstolfm \
		${DATADIR}/tools/updatepofiles

.for FILE in lazarus startlazarus lazbuild
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${DATADIR}
.endfor

.if !defined(NOPORTDOCS)
	@cd ${WRKDIR}/docs && \
		${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
	@${LN} -s ${DOCSDIR} ${DATADIR}/docs
.endif

.if !defined(NOPORTEXAMPLES)
	@cd ${WRKDIR}/examples && \
		${FIND} * -type d -exec ${MKDIR} "${EXAMPLESDIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${EXAMPLESDIR}/{}" \;
	@${LN} -s ${EXAMPLESDIR} ${DATADIR}/examples
.endif

	${INSTALL_SCRIPT} ${WRKSRC}/localize.sh ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/lazarus-wrapper ${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA}	${WRKSRC}/Makefile* ${WRKSRC}/fpmake*  ${DATADIR}
.for FILE in ${MAN1}
	${INSTALL_MAN} ${WRKDIR}/man1/${FILE} ${MAN1PREFIX}/man/man1
.endfor
	${LN} -s ${DATADIR}/lazbuild ${PREFIX}/bin/lazbuild

post-install:
	@${CAT} ${PKGMESSAGE}
.else
.include "${MASTERDIR}/Makefile.common"
.endif

.include <bsd.port.mk>
