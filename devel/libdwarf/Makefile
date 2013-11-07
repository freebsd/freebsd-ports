# Created by: joerg@FreeBSD.org
# $FreeBSD$

PORTNAME=	libdwarf
PORTVERSION=	20130207
CATEGORIES=	devel
MASTER_SITES=	http://pkgs.fedoraproject.org/repo/pkgs/libdwarf/libdwarf-20130207.tar.gz/64b42692e947d5180e162e46c689dfbf/

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	A library to analyze DWARF debugging information in ELF files

INSTALL_CONFLICT=	bsdlibdwarf*

WRKSRC=		${WRKDIR}/dwarf-${PORTVERSION}/libdwarf

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I. -I${LOCALBASE}/include

USE_DOS2UNIX=	*.h

PS_FILES=	dwarf.v2.pdf index.v2.pdf libdwarf2.1.pdf libdwarf2p.1.pdf mips_extensions.pdf

NO_STAGE=	yes
do-install:
		${INSTALL_DATA} ${WRKSRC}/libdwarf.a ${PREFIX}/lib
		${INSTALL_DATA} ${WRKSRC}/dwarf.h ${PREFIX}/include
		${INSTALL_DATA} ${WRKSRC}/libdwarf.h ${PREFIX}/include
		${MKDIR} ${PREFIX}/share/doc/libdwarf
		for f in ${PS_FILES}; do \
			${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/libdwarf ; \
		done

.include <bsd.port.mk>
