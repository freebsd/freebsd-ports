PORTNAME=	lazarus
DISTVERSION=	4.2
PKGNAMESUFFIX?=  -gtk2
PORTREVISION?=	0
CATEGORIES=	editors devel
DIST_SUBDIR=	freepascal

MAINTAINER?=	acm@FreeBSD.org
COMMENT?=	Portable Delphi-like IDE for the FreePascal compiler (GTK2)
WWW=		https://www.lazarus-ide.org/

CONFLICTS?=	lazarus-gtk2-devel lazarus-gtk3-devel lazarus-qt5 lazarus-qt5-devel \
		lazarus-qt6 lazarus-qt6-devel

BUILD_DEPENDS?=	${LOCALBASE}/bin/as:devel/binutils
RUN_DEPENDS?=	${LOCALBASE}/bin/as:devel/binutils \
		gmake:devel/gmake \
		${LOCALBASE}/share/fpc-source-${FPC_DEFAULT}/Makefile.fpc:lang/fpc${FPC_DEVELSUFFIX}-source

ONLY_FOR_ARCHS=	i386 amd64

USE_GITLAB=	yes
GL_ACCOUNT=	freepascal.org/lazarus
GL_PROJECT=	${PORTNAME}
GL_COMMIT=	e98683ddc052e8db4d0a046af5e04e365324ee4f

USES=		desktop-file-utils fpc:run gettext gmake iconv shared-mime-info xorg
USE_XORG=	x11
OPT?=		"-Sgic "

MAKE_ENV=	OPT=${OPT}
PLIST=		${WRKDIR}/pkg-plist
#WRKSRC?=	${WRKDIR}/${PORTNAME}
DATADIR?=	${PREFIX}/share/${PORTNAME}-${LAZARUS_BASE}

OPTIONS_DEFINE=		GDB
GDB_DESC=		Install a newest version  of gdb
OPTIONS_DEFAULT=	GDB

.include <bsd.port.options.mk>

LAZARUS_ARCH=	${ARCH:S,amd64,x86_64,}
LAZARUS_BASE=	4.2

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
USE_GNOME=	cairo gtk20 gdkpixbuf
.endif

post-extract:
	@${MKDIR} ${WRKDIR}/man1
	@${MV} ${WRKSRC}/install/man/man1/lazarus-ide.1 ${WRKDIR}/man1/
	@${MV} ${WRKSRC}/install/man/man1/lazbuild.1 ${WRKDIR}/man1/
	@${MV} ${WRKSRC}/install/man/man1/startlazarus.1 ${WRKDIR}/man1/
	@${MV} ${WRKSRC}/examples ${WRKDIR}/examples
	@${MV} ${WRKSRC}/docs ${WRKDIR}/docs
	@${RM} ${WRKSRC}/tools/.gitignore
	@${RM} ${WRKSRC}/Dockerfile.buildenv
	@${RM} ${WRKSRC}/buildenv.Dockerfile
	@${RM} ${WRKSRC}/.git*

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|startlazarus|${PORTNAME}|g' ${WRKSRC}/install/${PORTNAME}.desktop

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} bigide LCL_PLATFORM=${LCL_PLATFORM}

post-build:
	@cd ${WRKSRC} && \
		${RM} -R COPYING* README* debian localize.bat test *.orig *.bak startlazarus.app \
			ide/Makefile*.orig ide/Makefile*.bak lcl/interfaces/qt5/qtobjects.pas.orig \
			.git*
	@cd ${WRKSRC} && \
		${FIND} . -name ".gitignore" -exec ${RM} "{}" \;

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
		@${ECHO_CMD} share/man/man1/${m}.gz >> ${PLIST}
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
				${FIND} * -type f -exec ${INSTALL_DATA} -p {} "${STAGEDIR}${DATADIR}/${DIRE}/{}" \;
.endfor
	@${CHMOD} +x ${STAGEDIR}${DATADIR}/tools/svn2revisioninc ${STAGEDIR}${DATADIR}/tools/lazres ${STAGEDIR}${DATADIR}/tools/lrstolfm \
		${STAGEDIR}${DATADIR}/tools/updatepofiles

.for FILE in lazarus lazbuild startlazarus
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${STAGEDIR}${DATADIR}
.endfor

	@cd ${WRKDIR}/docs && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${DOCSDIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} {} "${STAGEDIR}${DOCSDIR}/{}" \;
	@${LN} -sf ${DOCSDIR} ${STAGEDIR}${DATADIR}/docs

	@cd ${WRKDIR}/examples && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${EXAMPLESDIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} {} "${STAGEDIR}${EXAMPLESDIR}/{}" \;
	@${LN} -sf ${EXAMPLESDIR} ${STAGEDIR}${DATADIR}/examples

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
	${INSTALL_MAN} ${WRKDIR}/man1/${FILE} ${STAGEDIR}${PREFIX}/share/man/man1
.endfor
	${LN} -sf ${DATADIR}/lazbuild ${STAGEDIR}${PREFIX}/bin/lazbuild

.include <bsd.port.mk>
