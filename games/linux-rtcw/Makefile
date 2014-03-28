# Created by: Nik Clayton <nik@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rtcw
DISTVERSION=	1.41b
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE}
MASTER_SITE_SUBDIR=	wolf/linux
PKGNAMEPREFIX=	linux-
DISTNAME=	wolf-linux-${DISTVERSION}.x86
EXTRACT_SUFX=	.run

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Return to Castle Wolfenstein (Linux version)

USES=		makeself
USE_LINUX=	yes
USE_LINUX_APPS=	xorglibs
NO_WRKSUBDIR=	yes

WRAPPERS=	wolf wolfded wolfsp

# Ignore older version which seems to be newer
PORTSCOUT=	skipv:1.41-3

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS NVIDIA_GL
NVIDIA_GL_DESC=	Use GL driver from nvidia-driver

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNVIDIA_GL}
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
USE_LINUX_APPS+=	dri
.endif

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
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in ${WRAPPERS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/Linux/x86/${f}.x86 ${STAGEDIR}${DATADIR}/${f}
	${INSTALL_SCRIPT} ${WRKDIR}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${CP} -a ${WRKSRC}/main ${WRKSRC}/pb ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Wolf[MS]P.xpm ${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} CHANGES INSTALL QUICKSTART *.txt ${STAGEDIR}${DOCSDIR}
	${CP} -a ${WRKSRC}/Docs ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
