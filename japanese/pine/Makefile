# New ports collection makefile for:	jp-pine
# Date created:		01 May 1996
# Whom:			masafumi
#
# $FreeBSD$
#

PORTNAME=	pine
PORTVERSION=	3.95
CATEGORIES=	japanese mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		${MASTER_SITE_PORTS_JP}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}lj1.1b2.tar.gz
DISTNAME=	${PORTNAME}${PORTVERSION}

PATCHFILES=	${DISTNAME}lj1.1b2-b3.diff.gz
PATCH_SITES=	${MASTER_SITE_PORTS_JP}

MAINTAINER=	max@FreeBSD.org

FORBIDDEN=	"Remotely exploitable buffer overflows."

BROKEN_ELF=	yes

INSTALLS_SHLIB=	yes

LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna
BUILD_DEPENDS=	${PREFIX}/lib/libcanna.a:${PORTSDIR}/japanese/Canna

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
MAN1=		pine.1 pilot.1 pico.1

pre-patch:
	@(cd ${WRKSRC}; \
	  ${TAR} zxf ${DISTDIR}/${DISTNAME}lj1.1b2.tar.gz; \
	  ${PATCH} -s -p0 < japan/${DISTNAME}lj1.1b2.diff)

do-build:
	(cd ${WRKSRC}; ./build bsf)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pico ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pilot ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pine ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bin/libpico.so.1.3 $(PREFIX)/lib
	${INSTALL_MAN} ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/pilot.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/pine.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/lib/pine
	${INSTALL_DATA} ${WRKSRC}/pine/pine.hlp ${PREFIX}/lib/pine
	${INSTALL_DATA} ${WRKSRC}/pine/pine.ndx ${PREFIX}/lib/pine
	${INSTALL_DATA} ${WRKSRC}/pine/pine_ja.hlp ${PREFIX}/lib/pine
	${INSTALL_DATA} ${WRKSRC}/pine/pine_ja.ndx ${PREFIX}/lib/pine

.include <bsd.port.mk>
