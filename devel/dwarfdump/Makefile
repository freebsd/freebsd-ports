# Created by: joerg@FreeBSD.org
# $FreeBSD$

PORTNAME=	dwarfdump
PORTVERSION=	20161124
CATEGORIES=	devel
MASTER_SITES=	http://www.prevanders.net/
DISTNAME=	libdwarf-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Tool to display DWARF debugging information in ELF files

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libdwarf.a:devel/libdwarf

WRKSRC=		${WRKDIR}/dwarf-${PORTVERSION}/dwarfdump

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/dwarfdump man/man1/dwarfdump.1.gz

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
	${INSTALL_PROGRAM} ${WRKSRC}/dwarfdump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dwarfdump.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
