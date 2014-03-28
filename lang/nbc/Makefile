# Created by: Ivan "Rambius" Ivanov <rambiusparkisanius@gmail.com>
# $FreeBSD$

# Also created by: Jason Bacon <jwbacon@tds.net>

PORTNAME=		nbc
PORTVERSION=		1.2.1.r4
PORTREVISION=		6
CATEGORIES=		lang
MASTER_SITES=		SF
MASTER_SITE_SUBDIR=	bricxcc/NBC_NXC/NBC%20release%20${PORTVERSION:S/.r/%20r/}
DISTNAME=		${PORTNAME}-${PORTVERSION}.src
EXTRACT_SUFX=		.tgz

MAINTAINER=		rene@FreeBSD.org
COMMENT=		Programming language for the LEGO MINDSTORMS NXT

MAKE_JOBS_UNSAFE=	yes
MAKEFILE=		nbcunix.mak
WRKSRC=			${WRKDIR}/NXT

OPTIONS_DEFINE=		DOCS ROBOCTL
ROBOCTL_DESC=		Include roboctl to communicate with the NXT

ROBOCTL_RUN_DEPENDS=	legoctl:${PORTSDIR}/devel/roboctl

USES=			dos2unix gmake
USE_FPC=		fcl-base fcl-image

PLIST_FILES=		bin/nbc \
			include/nbc/NXCDefs.h \
			include/nbc/NBCCommon.h \
			include/nbc/NXTDefs.h
PLIST_DIRS=		include/nbc

PORTDOCS=		Changelog \
			Readme

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' ${WRKSRC}/${MAKEFILE}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/nbc
	${INSTALL_PROGRAM} ${WRKSRC}/nbc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/nbc
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKDIR}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
