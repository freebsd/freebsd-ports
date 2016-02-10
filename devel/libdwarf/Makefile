# Created by: joerg@FreeBSD.org
# $FreeBSD$

PORTNAME=	libdwarf
PORTVERSION=	20130207
CATEGORIES=	devel
MASTER_SITES=	http://pkgs.fedoraproject.org/repo/pkgs/libdwarf/libdwarf-20130207.tar.gz/64b42692e947d5180e162e46c689dfbf/

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Library to analyze DWARF debugging information in ELF files

CONFLICTS_INSTALL=	bsdlibdwarf*

MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/dwarf-${PORTVERSION}/libdwarf

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I. -I${LOCALBASE}/include

USES=		dos2unix
DOS2UNIX_GLOB=	*.h

PS_FILES=	dwarf.v2.pdf index.v2.pdf libdwarf2.1.pdf libdwarf2p.1.pdf mips_extensions.pdf

do-install:
	${INSTALL_DATA} ${WRKSRC}/libdwarf.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/dwarf.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libdwarf.h ${STAGEDIR}${PREFIX}/include
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/libdwarf
.for f in ${PS_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/share/doc/libdwarf
.endfor

.include <bsd.port.mk>
