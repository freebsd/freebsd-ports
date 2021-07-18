# Created by: Marc van Woerkom <3d@FreeBSD.org>

PORTNAME=	quake3
DISTVERSION=	1.11-6
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	GENTOO
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-demo
DISTNAME=	linuxq3ademo-${DISTVERSION}.x86
EXTRACT_SUFX=	.gz.sh

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake III Arena Demo

# Converted from RESTRICTED
LICENSE=	Loki
LICENSE_NAME=	Loki
LICENSE_TEXT=	Restrictive license by Loki Software
LICENSE_PERMS=	auto-accept

USES=		linux
USE_LINUX=	dri
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

SUB_FILES=	q3demo

OPTIONS_DEFINE=	DOCS

do-extract:
	@cd ${WRKSRC} && ${TAIL} +165 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf -

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/q3demo ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/x86/glibc-2.0/q3demo ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/demoq3 ${STAGEDIR}${DATADIR}
	${LN} -s ${LINUXBASE}/usr/X11R6/lib/libGL.so.1 ${STAGEDIR}${DATADIR}/libGL.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/Help/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
