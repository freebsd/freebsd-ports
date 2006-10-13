# New ports collection makefile for:	dwarfdump
# Date created:		11 Feb 2005
# Whom:			joerg@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dwarfdump
DISTVERSION=	20060421
CATEGORIES=	devel
MASTER_SITES=	http://reality.sgiweb.org/davea/
DISTNAME=	libdwarf-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	A tool to display DWARF debugging information in ELF files

BUILD_DEPENDS=	${LOCALBASE}/lib/libelf.so.0:${PORTSDIR}/devel/libelf \
		${LOCALBASE}/lib/libdwarf.a:${PORTSDIR}/devel/libdwarf
RUN_DEPENDS=	${LOCALBASE}/lib/libelf.so.0:${PORTSDIR}/devel/libelf

WRKSRC=		${WRKDIR}/dwarf-${PORTVERSION}/dwarfdump

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.if (${MACHINE_ARCH} == "amd64")
ARCH=		x86_64
.endif

MAN1=		dwarfdump.1

.include <bsd.port.pre.mk>

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
