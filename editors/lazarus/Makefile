# $FreeBSD$

PORTNAME=	lazarus
PORTVERSION=	2.0.6
PKGNAMESUFFIX?=  -gtk2
PORTREVISION?=	1
CATEGORIES=	editors devel
MASTER_SITES=	SF/${PORTNAME}/Lazarus%20Zip%20_%20GZip/Lazarus%20${PORTVERSION} \
		LOCAL/acm/freepascal
DIST_SUBDIR=	freepascal

MAINTAINER?=	acm@FreeBSD.org
COMMENT?=	Portable Delphi-like IDE for the FreePascal compiler (GTK2)

CONFLICTS?=	${PORTNAME}-qt5-*

BUILD_DEPENDS?=	${LOCALBASE}/bin/as:devel/binutils \
		fpcres:lang/fpc-utils
RUN_DEPENDS?=	${LOCALBASE}/bin/as:devel/binutils \
		fpcres:lang/fpc-utils \
		${LOCALBASE}/share/fpc-source-${FPC_DEFAULT}/Makefile.fpc:lang/fpc-source

ONLY_FOR_ARCHS=	i386 amd64

USES=		desktop-file-utils fpc gettext gmake iconv shared-mime-info xorg
USE_FPC?=	chm cairo dblib fcl-base fcl-db fcl-fpcunit fcl-image fcl-json fcl-net \
		fcl-registry fcl-res fcl-web fcl-xml fppkg gtk2 ibase iconvenc mysql \
		numlib odbc opengl openssl oracle pasjpeg postgres regexpr rtl-extra \
		sqlite x11
USE_XORG=	x11
OPT?=		"-Sgic "

MAKE_ENV=	OPT=${OPT}
PLIST=		${WRKDIR}/pkg-plist
WRKSRC?=	${WRKDIR}/${PORTNAME}
DATADIR?=	${PREFIX}/share/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=		GDB
GDB_DESC=		Install a newest version  of gdb
OPTIONS_DEFAULT=	GTK2 GDB

.include <bsd.port.options.mk>

LAZARUS_ARCH=	${ARCH:S,amd64,x86_64,}

BUILDNAME=	${LAZARUS_ARCH}-${OPSYS:tl}
LCL_PLATFORM?=	gtk2

MAN1S=		lazarus-ide.1 lazbuild.1 startlazarus.1
SUB_FILES=	pkg-message
SUB_LIST+=	PORTSDIR="${PORTSDIR}"

.if ${PORT_OPTIONS:MGDB}
RUN_DEPENDS+=	${LOCALBASE}/bin/gdb:devel/gdb
.endif

.if ${PKGNAMESUFFIX} == "-gtk2"
USES+=		gnome
USE_GNOME=	cairo gtk20 gdkpixbuf2
.endif

post-extract:
	@${MKDIR} ${WRKDIR}/man1
	@${MV} ${WRKSRC}/install/man/man1/lazarus-ide.1 ${WRKDIR}/man1/
	@${MV} ${WRKSRC}/install/man/man1/lazbuild.1 ${WRKDIR}/man1/
	@${MV} ${WRKSRC}/install/man/man1/startlazarus.1 ${WRKDIR}/man1/
	@${MV} ${WRKSRC}/examples ${WRKDIR}/examples
	@${MV} ${WRKSRC}/docs ${WRKDIR}/docs

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|startlazarus|${PORTNAME}|g' ${WRKSRC}/install/${PORTNAME}.desktop

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} bigide LCL_PLATFORM=${LCL_PLATFORM}
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} tools LCL_PLATFORM=${LCL_PLATFORM}

post-build:
	@cd ${WRKSRC} && \
		${RM} -R COPYING* README* debian localize.bat test *.orig *.bak startlazarus.app \
			ide/Makefile*.orig ide/Makefile*.bak

pre-install:
	@${ECHO} "#!/bin/sh" > ${WRKDIR}/lazarus-wrapper
	@${ECHO} "cd ${DATADIR} || exit 1 " >> ${WRKDIR}/lazarus-wrapper
	@${ECHO} "exec ./startlazarus" >> ${WRKDIR}/lazarus-wrapper

	@${RM} ${PLIST}
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

	@${ECHO_CMD} "share/applications/lazarus.desktop" >> ${PLIST}

.	for RESO in 128 16 256 32 48 64
		@${ECHO_CMD} share/icons/hicolor/${RESO}x${RESO}/apps/lazarus.png >> ${PLIST}
.	endfor

	@cd ${WRKSRC}/images/mimetypes && \
		${FIND} * -type f -name "*.png" | ${SORT} | ${SED} -e 's|^|share/icons/hicolor/48x48/mimetypes/|' >> ${PLIST}

	@${ECHO_CMD} "share/icons/hicolor/scalable/apps/lazarus.svg" >> ${PLIST}
	@${ECHO_CMD} "share/mime/packages/lazarus.xml" >> ${PLIST}

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


.for RESO in 128 16 256 32 48 64
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${RESO}x${RESO}/apps
	${INSTALL_DATA} ${WRKSRC}/images/icons/${PORTNAME}${RESO}x${RESO}.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/${RESO}x${RESO}/apps/${PORTNAME}.png
.endfor

	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/mimetypes
	@cd ${WRKSRC}/images/mimetypes && \
		${FIND} * -type f -name "*.png" -exec ${INSTALL_DATA} {} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/mimetypes/{} \;

	@${INSTALL_DATA} ${WRKSRC}/install/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop

	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	@${INSTALL_DATA} ${WRKSRC}/images/icons/${PORTNAME}.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}.svg

	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	@${INSTALL_DATA} ${WRKSRC}/install/${PORTNAME}-mime.xml ${STAGEDIR}${PREFIX}/share/mime/packages/${PORTNAME}.xml

	${INSTALL_SCRIPT} ${WRKSRC}/localize.sh ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/lazarus-wrapper ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA}	${WRKSRC}/Makefile* ${WRKSRC}/fpmake*  ${STAGEDIR}${DATADIR}
.for FILE in ${MAN1S}
	${INSTALL_MAN} ${WRKDIR}/man1/${FILE} ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor
	${LN} -s ${DATADIR}/lazbuild ${STAGEDIR}${PREFIX}/bin/lazbuild

.include <bsd.port.mk>
