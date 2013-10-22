# Created by: Nik Clayton <nik@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rtcw
DISTVERSION=	1.41b
CATEGORIES=	games linux
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE}
MASTER_SITE_SUBDIR=	wolf/linux
PKGNAMEPREFIX=	linux-
DISTNAME=	wolf-linux-${DISTVERSION}.x86

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Return to Castle Wolfenstein (Linux version)

USE_MAKESELF=	yes
USE_LINUX=	yes
USE_LINUX_APPS=	dri xorglibs
NO_WRKSUBDIR=	yes

WRAPPERS=	wolf wolfded wolfsp

# Ignore older version which seems to be newer
PORTSCOUT=	skipv:1.41-3

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

# XXX: should probably be converted to use the LICENSE framework
post-extract:
	@${MV} ${WRKSRC}/pb/PB_EULA.txt ${WRKSRC}

do-build:
.for f in ${WRAPPERS}
	(${ECHO_CMD} "#!${SH}"; ${ECHO_CMD}; \
	 ${ECHO_CMD} "cd ${DATADIR} || exit 1"; \
	 ${ECHO_CMD} 'exec ./${f} "$$@"') > ${WRKDIR}/${f}
.endfor

do-install:
	@${MKDIR} ${DATADIR}
.for f in ${WRAPPERS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Linux/x86/${f}.x86 ${DATADIR}/${f}
	${INSTALL_SCRIPT} ${WRKDIR}/${f} ${PREFIX}/bin
.endfor
	${CP} -a ${WRKSRC}/main ${WRKSRC}/pb ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Wolf[MS]P.xpm ${PREFIX}/share/pixmaps
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} CHANGES INSTALL QUICKSTART *.txt ${DOCSDIR}
	${CP} -a ${WRKSRC}/Docs ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
