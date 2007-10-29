# New ports collection makefile for:	libdwarf
# Date created:		11 Feb 2005
# Whom:			joerg@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libdwarf
PORTVERSION=	20070703
CATEGORIES=	devel
MASTER_SITES=	http://reality.sgiweb.org/davea/

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	A library to analyze DWARF debugging information in ELF files

BUILD_DEPENDS=	${LOCALBASE}/lib/libelf.so.0:${PORTSDIR}/devel/libelf

WRKSRC=		${WRKDIR}/dwarf-${PORTVERSION}/libdwarf

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PS_FILES=	dwarf.v2.pdf index.v2.pdf libdwarf2.1.pdf libdwarf2p.1.pdf mips_extensions.pdf

do-install:
		${INSTALL_DATA} ${WRKSRC}/libdwarf.a ${PREFIX}/lib
		${INSTALL_DATA} ${WRKSRC}/dwarf.h ${PREFIX}/include
		${INSTALL_DATA} ${WRKSRC}/libdwarf.h ${PREFIX}/include
		${MKDIR} ${PREFIX}/share/doc/libdwarf
		for f in ${PS_FILES}; do \
			${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/libdwarf ; \
		done

.include <bsd.port.mk>
