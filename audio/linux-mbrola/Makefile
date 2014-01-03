# Created by: trevor
# $FreeBSD$

PORTNAME=	mbrola
PORTVERSION=	3.0.1
CATEGORIES=	audio accessibility linux
MASTER_SITES=	http://tcts.fpms.ac.be/synthesis/mbrola/bin/pclinux/ \
		http://www.festvox.org/mbrola/bin/pclinux/
PKGNAMEPREFIX=	linux-
DISTNAME=	mbr301h
DIST_SUBDIR=	mbrola-linux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MBROLA speech synthesizer for Linux

RUN_DEPENDS=	${LOCALBASE}/share/mbrolavox:${PORTSDIR}/audio/mbrolavox

CONFLICTS=	mbrola-*
NO_BUILD=	yes
ONLY_FOR_ARCHS=	amd64 i386
USE_LINUX=	yes
NO_STAGE=	yes
USE_ZIP=	yes
RESTRICTED=	for non-commercial, non-military applications only
WRKSRC=		${WRKDIR}/mbr301h
PLIST=		${WRKDIR}/plist

PLIST_DIRS=	share/doc/mbrola
PLIST_FILES=	bin/mbrola

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_FILES+=	share/doc/mbrola/readme.txt
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.zip -d ${WRKSRC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mbrola-linux-i386 ${PREFIX}/bin/mbrola
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
