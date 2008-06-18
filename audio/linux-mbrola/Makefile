# New ports collection makefile for:		linux-mbrola
# Date created:					2003-10-05
# Whom:						trevor
#
# $FreeBSD$
#

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
ONLY_FOR_ARCHS=	alpha amd64 i386
USE_LINUX=	yes
USE_ZIP=	yes
RESTRICTED=	for non-commercial, non-military applications only
WRKSRC=		${WRKDIR}/mbr301h
PLIST=		${WRKDIR}/plist

PLIST_DIRS=	share/doc/mbrola
PLIST_FILES=	bin/mbrola
.if !defined(NOPORTDOCS)
PLIST_FILES+=	share/doc/mbrola/readme.txt
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@unzip -qo ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.zip -d ${WRKSRC}

do-patch:
	@${RM} -f ${WRKSRC}/mbrola-FreeBSD-i386-aout

.include <bsd.port.pre.mk>

do-install:
.if (${ARCH} == "alpha")
	@${INSTALL_PROGRAM} ${WRKSRC}/mbrola-linux-alpha ${PREFIX}/bin/mbrola
.else
	@${INSTALL_PROGRAM} ${WRKSRC}/mbrola-linux-i386 ${PREFIX}/bin/mbrola
.endif
	@${CHMOD} +x ${PREFIX}/bin/mbrola
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
