# New ports collection makefile for:	lazarus
# Date Created:				2006-02-09
# Whom:					Shaun Amott <shaun@inerd.com>
#
# $FreeBSD$
#

PORTNAME=	lazarus
PORTVERSION=	0.9.24
PORTREVISION=	2
CATEGORIES=	editors devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:S/$/-0/}
DIST_SUBDIR=	freepascal

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A portable Delphi-like IDE for the FreePascal compiler

ONLY_FOR_ARCHS=	i386

USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	#
WANT_FPC_ALL=	yes

MAKE_ENV=	OPT="-Sgic -Fu${UNITSDIR}/* -Fl${LOCALBASE}/lib" LCL_PLATFORM=${LCL_PLATFORM}
MAN1=		lazbuild.1
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	GTK2	"Use gtk20 interface instead of gtk12"	off \
		BIGIDE	"Compile additional components"	off

.include <bsd.port.pre.mk>

.if defined(WITH_GTK2)
USE_GNOME=	gtk20
LCL_PLATFORM=	gtk2
.else
USE_GNOME=	gtk12 gdkpixbuf
LCL_PLATFORM=	gtk
.endif

.if defined(WITH_BIGIDE)
LAZARUS_TARGET=	bigide lazbuilder
.endif

post-extract:
	@${MKDIR} ${WRKDIR}/man1
	@${MV} ${WRKSRC}/docs/lazbuild.1 ${WRKDIR}/man1
	@${MV} ${WRKSRC}/examples ${WRKDIR}/examples
	@${MV} ${WRKSRC}/docs ${WRKDIR}/docs

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/${MAKEFILE}

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${LAZARUS_TARGET}

post-build:
	@cd ${WRKSRC} && \
		${RM} -Rf COPYING* README* debian localize.bat test *.orig *.bak

pre-install:
	@${ECHO} "#!/bin/sh" > ${WRKDIR}/lazarus-wrapper
	@${ECHO} "cd ${DATADIR} || exit 1 " >> ${WRKDIR}/lazarus-wrapper
	@${ECHO} "exec ./startlazarus" >> ${WRKDIR}/lazarus-wrapper

	@${RM} -f ${PLIST}

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
	${INSTALL_MAN} ${WRKDIR}/man1/${MAN1} ${MAN1PREFIX}/man/man1
	${LN} -s ${DATADIR}/lazbuild ${PREFIX}/bin/lazbuild

.include <bsd.port.post.mk>
