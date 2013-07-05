# Created by: Ivan "Rambius" Ivanov <rambiusparkisanius@gmail.com>
# $FreeBSD$

# Also created by: Jason Bacon <jwbacon@tds.net>

PORTNAME=		nbc
PORTVERSION=		1.2.1.r4
PORTREVISION=		5
CATEGORIES=		lang
MASTER_SITES=		SF
MASTER_SITE_SUBDIR=	bricxcc/NBC_NXC/NBC%20release%20${PORTVERSION:S/.r/%20r/}
DISTNAME=		${PORTNAME}-${PORTVERSION}.src
EXTRACT_SUFX=		.tgz

MAINTAINER=		rene@FreeBSD.org
COMMENT=		NBC is a programming language for the LEGO MINDSTORMS NXT product

MAKE_JOBS_UNSAFE=	yes
MAKEFILE=		nbcunix.mak

OPTIONS_DEFINE=	DOCS ROBOCTL

ROBOCTL_DESC=	Include roboctl to communicate with the NXT

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MROBOCTL}
RUN_DEPENDS=		legoctl:${PORTSDIR}/devel/roboctl
.endif

USES=			gmake
USE_DOS2UNIX=		yes
USE_FPC=		fcl-base fcl-image

WRKSRC=			${WRKDIR}/NXT

PLIST_FILES=		bin/nbc \
			include/nbc/NXCDefs.h \
			include/nbc/NBCCommon.h \
			include/nbc/NXTDefs.h
PLIST_DIRS=		include/nbc

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=		Changelog \
			Readme
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' ${WRKSRC}/${MAKEFILE}

do-install:
	${MKDIR} ${PREFIX}/include/nbc
	${INSTALL_PROGRAM} ${WRKSRC}/nbc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/nbc
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/doc/Changelog ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/doc/Readme ${DOCSDIR}
.endif

.include <bsd.port.mk>
