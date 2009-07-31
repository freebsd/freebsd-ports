# New ports collection makefile for:	gens
# Date created:			22 Jun 2005
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	gens
PORTVERSION=	2.12a
PORTREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Gens212a1SrcL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sega Genesis/CD/32X emulator

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

WRKSRC=		${WRKDIR}/${PORTNAME}_linux/${PORTNAME}
USE_ZIP=	yes
USE_SDL=	sdl
USE_GNOME=	gtk20
USE_GMAKE=	yes

ONLY_FOR_ARCHS=	i386

post-patch:
	${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|g++|${CXX}|' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|%%LDFLAGS%%|${LDFLAGS}|' ${WRKSRC}/Makefile
	@${CAT} ${FILESDIR}/gens.in | ${SED} -e 's,%%PREFIX%%,${PREFIX},g' > ${WRKDIR}/gens

do-install:
	${MKDIR} ${PREFIX}/share/gens
	${MKDIR} ${PREFIX}/share/gens/resource
	${INSTALL_SCRIPT} ${WRKDIR}/gens ${PREFIX}/bin/gens
	${INSTALL_PROGRAM} ${WRKSRC}/gens ${PREFIX}/share/gens/gens
	${INSTALL_DATA} ${WRKSRC}/resource/* ${PREFIX}/share/gens/resource
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_linux/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
