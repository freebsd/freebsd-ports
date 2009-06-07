# New ports collection makefile for:	Return to Castle Wolfenstein
# Date created:				Sun Jun  3 00:52:38 EDT 2001
# Whom:					nik@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	rtcw
PORTVERSION=	1.41b
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	games linux
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE}
MASTER_SITE_SUBDIR=	wolf/linux
DISTNAME=	wolf-linux-${PORTVERSION}.x86

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Return to Castle Wolfenstein for Linux

USE_MAKESELF=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	dri xorglibs
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message
WRAPPERS=	wolf wolfded wolfsp

# Ignore older version which seems to be newer.
PORTSCOUT=	skipv:1.41-3

# Should be in bsd.commands.mk. Remove when ports/118749 is committed.
UNMAKESELF_CMD?=	${LOCALBASE}/bin/unmakeself

post-extract:
	@${MV} ${WRKSRC}/pb/PB_EULA.txt ${WRKSRC}

do-build:
.for f in ${WRAPPERS}
	@(${ECHO_CMD} "#!${SH}"; \
	  ${ECHO_CMD} "cd ${DATADIR} || exit 1"; \
	  ${ECHO_CMD} 'exec ./${f} "$$@"') > ${WRKDIR}/${f}
.endfor

do-install:
	${MKDIR} ${DATADIR}
.for f in ${WRAPPERS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Linux/x86/${f}.x86 ${DATADIR}/${f}
	${INSTALL_SCRIPT} ${WRKDIR}/${f} ${PREFIX}/bin
.endfor
	${CP} -r ${WRKSRC}/main ${WRKSRC}/pb ${DATADIR}
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/Wolf[MS]P.xpm ${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} CHANGES INSTALL QUICKSTART *.txt ${DOCSDIR}
	${CP} -R ${WRKSRC}/Docs ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
