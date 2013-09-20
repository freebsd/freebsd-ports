# Created by: joerg@FreeBSD.org
# $FreeBSD$

PORTNAME=	dwarfdump
PORTVERSION=	20130207
CATEGORIES=	devel
MASTER_SITES=	http://reality.sgiweb.org/davea/
DISTNAME=	libdwarf-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	A tool to display DWARF debugging information in ELF files

BUILD_DEPENDS=	${LOCALBASE}/lib/libdwarf.a:${PORTSDIR}/devel/libdwarf

WRKSRC=		${WRKDIR}/dwarf-${PORTVERSION}/dwarfdump

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

MAN1=		dwarfdump.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
ARCH=		x86_64
.endif

FILES_TO_PATCH=print_reloc.c

post-patch:
	${REINPLACE_CMD} \
	-e 's/Elf64_Xword/Elf64_Word/g' \
	-e 's/Elf64_Sxword/Elf64_Sword/g' \
	${FILES_TO_PATCH:S,^,${WRKSRC}/,}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/dwarfdump ${PREFIX}/bin
		${INSTALL_DATA} ${WRKSRC}/dwarfdump.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
