# New ports collection makefile for:		mbrola
# Date created:					2003-10-04
# Whom:						trevor
#
# $FreeBSD$
#

PORTNAME=	mbrola
PORTVERSION=	3.0.1
CATEGORIES=	audio accessibility
MASTER_SITES?=	http://www.tcts.fpms.ac.be/synthesis/mbrola/bin/freebsd/
DISTNAME=	mbr301h
EXTRACT_SUFX=	.zip
DIST_SUBDIR?=	mbrola-freebsd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MBROLA voice synthesizer

.include <bsd.port.pre.mk>

.if !defined(USE_LINUX)
LIB_DEPENDS=	c.3:${PORTSDIR}/misc/compat3x
.endif
RUN_DEPENDS+=	${PREFIX}/share/mbrolavox:${PORTSDIR}/audio/mbrolavox

CONFLICTS?=	linux-mbrola-*
NO_BUILD=	yes
ONLY_FOR_ARCHS?=i386
PLIST_DIRS=	share/doc/mbrola
PLIST_FILES=	bin/mbrola
.if !defined(NOPORTDOCS)
PLIST_FILES+=	share/doc/mbrola/readme.txt
.endif
RESTRICTED=	"for non-commercial, non-military applications only"
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/mbr301h
PLIST=		${WRKDIR}/plist

do-extract:
	@${MKDIR} ${WRKSRC}
	@unzip -qo ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.zip -d ${WRKSRC}

do-patch:
	@${RM} -f ${WRKSRC}/mbrola-FreeBSD-i386-aout

do-install:
.if defined(USE_LINUX)
.if (${ARCH} == "alpha")
	@${INSTALL_PROGRAM} ${WRKSRC}/mbrola-linux-alpha ${PREFIX}/bin/mbrola
.elif (${ARCH} == "i386")
	@${INSTALL_PROGRAM} ${WRKSRC}/mbrola-linux-i386 ${PREFIX}/bin/mbrola
.elif (${ARCH} == "powerpc")
	@${INSTALL_PROGRAM} ${WRKSRC}/mbrola206a-linux-ppc ${PREFIX}/bin/mbrola
.elif (${ARCH} == "sparc64")
	@${INSTALL_PROGRAM} ${WRKSRC}/mbrola-SuSElinux-ultra1.dat \
		${PREFIX}/bin/mbrola
.endif
.else
	@${INSTALL_PROGRAM} ${WRKSRC}/mbrola-FreeBSD-i386-elf \
		${PREFIX}/bin/mbrola
.endif # defined(USE_LINUX)
	@${CHMOD} +x ${PREFIX}/bin/mbrola
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
