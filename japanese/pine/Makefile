# New ports collection makefile for:	ja-pine
# Date created:		01 May 1996
# Whom:			masafumi
#
# $FreeBSD$
#

PORTNAME=	pine
PORTVERSION=	3.96
CATEGORIES=	japanese mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/old/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	max
DISTNAME=	${PORTNAME}${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.Z \${PORTNAME}${PORTVERSION}.tar.Z \
		${DISTNAME}lj1.1b7.tar.gz
EXTRACT_ONLY=	${DISTNAME}.tar.Z

MAINTAINER=	max@FreeBSD.org

LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna
BUILD_DEPENDS=	${LOCALBASE}/lib/libcanna.a:${PORTSDIR}/japanese/Canna

FORBIDDEN=	"Remotely exploitable buffer overflows."

INSTALLS_SHLIB=	yes
MAN1=		pine.1 pilot.1 pico.1

pre-patch:
	@(cd ${WRKSRC}; \
	  ${TAR} zxf ${DISTDIR}/${DISTNAME}lj1.1b7.tar.gz; \
	  ${PATCH} -s -p1 < ${DISTNAME}lj1.1b7.diff)

do-build:
	(cd ${WRKSRC}; ./build bsf)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pico ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pilot ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pine ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/bin/libpico.so.1.3 $(PREFIX)/lib/libpico.so.1
	${LN} -sf ${PREFIX}/lib/libpico.so.1 ${PREFIX}/lib/libpico.so
	${INSTALL_MAN} ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/pilot.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/pine.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/lib/pine
	${INSTALL_DATA} ${WRKSRC}/pine/pine.hlp ${PREFIX}/lib/pine
	${INSTALL_DATA} ${WRKSRC}/pine/pine.ndx ${PREFIX}/lib/pine
	${INSTALL_DATA} ${WRKSRC}/pine/pine_ja.hlp ${PREFIX}/lib/pine
	${INSTALL_DATA} ${WRKSRC}/pine/pine_ja.ndx ${PREFIX}/lib/pine

.include <bsd.port.mk>
