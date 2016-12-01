# Created by: Shaun Amott <shaun@inerd.com>
# $FreeBSD$

PORTNAME=	lazarus
PORTVERSION=	1.6.2
DISTVERSIONSUFFIX=	-0
PORTREVISION?=	0
CATEGORIES=	editors devel
MASTER_SITES=	SF/${PORTNAME}/Lazarus%20Zip%20_%20GZip/Lazarus%20${PORTVERSION:S/.0//} \
		LOCAL/acm/freepascal
DIST_SUBDIR=	freepascal

MAINTAINER?=	freebsd-fpc@FreeBSD.org
COMMENT?=	Portable Delphi-like IDE for the FreePascal compiler

BUILD_DEPENDS?=	#
RUN_DEPENDS?=	#

ONLY_FOR_ARCHS=	i386 amd64

USES=		gmake
USE_GNOME=	#
USE_FPC?=	cairo dblib fcl-base fcl-db fcl-fpcunit fcl-image fcl-json fcl-net \
		fcl-registry fcl-res fcl-web fcl-xml gtk2 ibase iconvenc rtl-extra \
		mysql numlib odbc openssl oracle pasjpeg postgres sqlite x11
OPT?=		"-Sgic "

MAKE_ENV=	OPT=${OPT}
PLIST=		${WRKDIR}/pkg-plist
WRKSRC?=	${WRKDIR}/${PORTNAME}
DATADIR?=	${PREFIX}/share/${PORTNAME}-${PORTVERSION}

.if !defined(PKGNAMESUFFIX)
OPTIONS_DEFINE=		GDB
OPTIONS_SINGLE=		LCL
OPTIONS_SINGLE_LCL=	GTK2 QT4

GDB_DESC=		Install a newest version  of gdb
GTK2_DESC=		Use gtk20 interface
QT4_DESC=		Use qt4 interface

OPTIONS_DEFAULT=	GTK2 GDB
.endif

.include <bsd.port.options.mk>

LAZARUS_ARCH=	${ARCH:S,amd64,x86_64,}

BUILDNAME=	${LAZARUS_ARCH}-${OPSYS:tl}
LCL_UNITS_DIR=	${LOCALBASE}/share/${PORTNAME}-${PORTVERSION}/lcl/units/${BUILDNAME}

.if !defined(PKGNAMESUFFIX)
BUILD_DEPENDS+=	fpcres:lang/fpc-utils \
		${LCL_UNITS_DIR}/alllclunits.ppu:editors/lazarus-lcl-units \
		${LCL_UNITS_DIR}/nogui/interfaces.ppu:editors/lazarus-lcl-nogui
RUN_DEPENDS+=	fpcres:lang/fpc-utils \
		${LCL_UNITS_DIR}/alllclunits.ppu:editors/lazarus-lcl-units \
		${LCL_UNITS_DIR}/nogui/interfaces.ppu:editors/lazarus-lcl-nogui

USES+=		gettext iconv
USE_FPC+=	chm

MAN1S=		lazarus-ide.1 lazbuild.1 startlazarus.1
SUB_FILES=	pkg-message
SUB_LIST+=	PORTSDIR="${PORTSDIR}"

.if ${PORT_OPTIONS:MGDB}
RUN_DEPENDS+=	${LOCALBASE}/bin/gdb:devel/gdb
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20 gdkpixbuf
LCL_PLATFORM=	gtk2
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus-lcl-gtk2
RUN_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus-lcl-gtk2
.endif

.if ${PORT_OPTIONS:MQT4}
LIB_DEPENDS+=	libQt4Pas.so:x11-toolkits/qt4pas
LCL_PLATFORM=	qt
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus-lcl-qt
RUN_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus-lcl-qt
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
			-e 's|tools: lcl|tools:|g' -e '3080d' -e '3082d' -e '3083d' -e '3084d' -e '3085d' -e '3086d' ${WRKSRC}/${MAKEFILE}

pre-build:
	@${LN} -sf ${LOCALBASE}/share/${PORTNAME}-${PORTVERSION}/lcl/units ${WRKSRC}/lcl/units
	@${LN} -sf ${LOCALBASE}/share/${PORTNAME}-${PORTVERSION}/components/debuggerintf/lib ${WRKSRC}/components/debuggerintf/lib
	@${LN} -sf ${LOCALBASE}/share/${PORTNAME}-${PORTVERSION}/components/ideintf/units ${WRKSRC}/components/ideintf/units
	@${LN} -sf ${LOCALBASE}/share/${PORTNAME}-${PORTVERSION}/components/synedit/units ${WRKSRC}/components/synedit/units
	@${LN} -sf ${LOCALBASE}/share/${PORTNAME}-${PORTVERSION}/components/lazcontrols/lib ${WRKSRC}/components/lazcontrols/lib
	@${LN} -sf ${LOCALBASE}/share/${PORTNAME}-${PORTVERSION}/components/lazdebuggergdbmi/lib ${WRKSRC}/components/lazdebuggergdbmi/lib

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} registration lazutils codetools bigide starter lazbuild LCL_PLATFORM=${LCL_PLATFORM}
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} tools LCL_PLATFORM=${LCL_PLATFORM}

post-build:
	@cd ${WRKSRC} && \
		${RM} -R COPYING* README* debian localize.bat test *.orig *.bak startlazarus.app \
			ide/Makefile*.orig ide/Makefile*.bak lcl/units components/ideintf/units \
				components/synedit/units components/lazcontrols/lib

pre-install:
	@${ECHO} "#!/bin/sh" > ${WRKDIR}/lazarus-wrapper
	@${ECHO} "cd ${DATADIR} || exit 1 " >> ${WRKDIR}/lazarus-wrapper
	@${ECHO} "exec ./startlazarus" >> ${WRKDIR}/lazarus-wrapper

	@${RM} ${PLIST}
	@${RM} ${WRKSRC}/lcl/units
	@${RM} -r ${WRKSRC}/components/chmhelp/lhelp/lhelp.app/Contents/MacOS \
		${WRKSRC}/lazarus.app/Contents/MacOS \
		${WRKSRC}/lazarus.app/Contents/Resources/startlazarus.app/Contents/MacOS

.	for FILE in bin/lazarus bin/lazbuild
		@${ECHO_CMD} ${FILE} >> ${PLIST}
.	endfor
.	for m in ${MAN1S}
		@${ECHO_CMD} man/man1/${m}.gz >> ${PLIST}
.	endfor

	@${ECHO_CMD} "%%DATADIR%%/docs" >> ${PLIST}
	@cd ${WRKDIR}/docs && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DOCSDIR%%/|' >> ${PLIST}

	@${ECHO_CMD} "%%DATADIR%%/examples" >> ${PLIST}
	@cd ${WRKDIR}/examples && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%EXAMPLESDIR%%/|' >> ${PLIST} && \
		${FIND} * -type d -empty | ${SORT} | ${SED} -e 's|^|@dir %%EXAMPLESDIR%%/|' >> ${PLIST}

	@cd ${WRKSRC} && \
		${FIND} * -type f | ${SORT} | ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
		${FIND} * -type d -empty | ${SORT} | ${SED} -e 's|^|@dir %%DATADIR%%/|' >> ${PLIST}

do-install:
.for DIRE in components converter debugger designer doceditor ide images install languages lazarus.app lcl \
	packager tools units
		@${MKDIR} ${STAGEDIR}${DATADIR}/${DIRE}
		@cd ${WRKSRC}/${DIRE} && \
			${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${DATADIR}/${DIRE}/{}" \; && \
				${FIND} * -type f -exec ${INSTALL_DATA} {} "${STAGEDIR}${DATADIR}/${DIRE}/{}" \;
.endfor
	@${CHMOD} +x ${STAGEDIR}${DATADIR}/tools/svn2revisioninc ${STAGEDIR}${DATADIR}/tools/lazres ${STAGEDIR}${DATADIR}/tools/lrstolfm \
		${STAGEDIR}${DATADIR}/tools/updatepofiles

.for FILE in lazarus startlazarus lazbuild
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${STAGEDIR}${DATADIR}
.endfor

	@cd ${WRKDIR}/docs && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${DOCSDIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} {} "${STAGEDIR}${DOCSDIR}/{}" \;
	@${LN} -s ${DOCSDIR} ${STAGEDIR}${DATADIR}/docs

	@cd ${WRKDIR}/examples && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${EXAMPLESDIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} {} "${STAGEDIR}${EXAMPLESDIR}/{}" \;
	@${LN} -s ${EXAMPLESDIR} ${STAGEDIR}${DATADIR}/examples

	${INSTALL_SCRIPT} ${WRKSRC}/localize.sh ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/lazarus-wrapper ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA}	${WRKSRC}/Makefile* ${WRKSRC}/fpmake*  ${STAGEDIR}${DATADIR}
.for FILE in ${MAN1S}
	${INSTALL_MAN} ${WRKDIR}/man1/${FILE} ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor
	${LN} -s ${DATADIR}/lazbuild ${STAGEDIR}${PREFIX}/bin/lazbuild

.else
.include "${MASTERDIR}/Makefile.common"
.endif

.include <bsd.port.mk>
