# New ports collection makefile for:	lazarus
# Date Created:				2006-02-09
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	lazarus
PORTVERSION=	0.9.26.2
PORTREVISION=	2
CATEGORIES=	editors devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/$/-0/}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	freepascal

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A portable Delphi-like IDE for the FreePascal compiler

ONLY_FOR_ARCHS=	i386

USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	#
USE_FPC=	fcl-base fcl-db fcl-image fcl-process fcl-registry fcl-xml \
		iconvenc pasjpeg x11

MAKE_ENV=	OPT="-Sgic -Fu${UNITSDIR}/* -Fl${LOCALBASE}/lib ${OPT_EXTRA}"
MAN1=		lazarus-ide.1 lazbuild.1 startlazarus.1
PLIST=		${WRKDIR}/pkg-plist
SUB_FILES=	pkg-message
SUB_LIST+=	PORTSDIR="${PORTSDIR}"
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	GTK2	"Use gtk20 interface instead of gtk12"	on \
		QT4	"Use qt4 interface" off

.include <bsd.port.pre.mk>

.if defined(WITH_GTK2) && defined(WITH_QT4)
IGNORE=		Please select only one option QT4 or GTK2, don't select both options
.endif

.if defined(WITH_GTK2)
USE_FPC+=	gtk2
USE_GNOME=	gtk20
LCL_PLATFORM=	gtk2
.else
USE_FPC+=	gtk1
USE_GNOME=	gtk12 gdkpixbuf
LCL_PLATFORM=	gtk
.endif

.if defined(WITH_QT4)
BUILD_DEPENDS+=	${LOCALBASE}/lib/qt4/libqt4intf.so:${PORTSDIR}/x11-toolkits/qt4pas
LCL_PLATFORM=	qt
OPT_EXTRA=	"-dUSE_QT_44"
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
		${WRKSRC}/${MAKEFILE}

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} LCL_PLATFORM=${LCL_PLATFORM}

post-build:
	@cd ${WRKSRC} && \
		${RM} -Rf COPYING* README* debian localize.bat test *.orig *.bak startlazarus.app \
			ide/Makefile*.orig ide/Makefile*.bak

pre-install:
	@${ECHO} "#!/bin/sh" > ${WRKDIR}/lazarus-wrapper
	@${ECHO} "cd ${DATADIR} || exit 1 " >> ${WRKDIR}/lazarus-wrapper
	@${ECHO} "exec ./startlazarus" >> ${WRKDIR}/lazarus-wrapper

	@${RM} -f ${PLIST}

.	for FILE in bin/lazarus bin/lazbuild etc/lazbuild.cfg
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
			${FIND} * -type d | ${SORT} -r | ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}
	@${ECHO_CMD} "@dirrm %%DATADIR%%" >> ${PLIST}

do-install:
.for DIRE in components converter debugger designer doceditor ide ideintf images install languages lazarus.app lcl \
	packager tools units
		@${MKDIR} ${DATADIR}/${DIRE}
		@cd ${WRKSRC}/${DIRE} && \
			${FIND} * -type d -exec ${MKDIR} "${DATADIR}/${DIRE}/{}" \; && \
				${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/${DIRE}/{}" \;
.endfor
	@${CHMOD} +x ${DATADIR}/tools/svn2revisioninc

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
	${INSTALL_DATA}	${WRKSRC}/Makefile* ${DATADIR}
.for FILE in ${MAN1}
	${INSTALL_MAN} ${WRKDIR}/man1/${FILE} ${MAN1PREFIX}/man/man1
.endfor
	${LN} -s ${DATADIR}/lazbuild ${PREFIX}/bin/lazbuild

	@${ECHO_CMD} "# Current lazarus interface" > ${PREFIX}/etc/lazbuild.cfg
	@${ECHO_CMD} "LCL_PLATFORM=${LCL_PLATFORM}" >> ${PREFIX}/etc/lazbuild.cfg

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
