PORTNAME=	cxxtools
PORTVERSION=	2.2.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.tntnet.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of general-purpose C++ classes

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		does not configure: error: check for atomictype failed
BROKEN_mips=		does not configure: in section .data.rel.ro of csvdeserializer-test.o: defined in discarded section
BROKEN_mips64=		does not configure: in section .data.rel.ro of csvdeserializer-test.o: defined in discarded section
BROKEN_riscv64=		does not configure: error: check for atomictype failed
BROKEN_sparc64=		does not configure

USES=		cpe iconv libtool localbase pathfix
CPE_VENDOR=	tntnet
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
PLIST_SUB+=	X86_64_ONLY=""
.else
PLIST_SUB+=	X86_64_ONLY="@comment "
.endif

.if ${ARCH} == i386
PLIST_SUB+=	I386_ONLY=""
.else
PLIST_SUB+=	I386_ONLY="@comment "
.endif

.if (${ARCH} == amd64) || (${ARCH} == i386)
PLIST_SUB+=	X86_ONLY=""
.else
PLIST_SUB+=	X86_ONLY="@comment "
.endif

.if ${ARCH} == aarch64 || ${ARCH:Marm*}
PLIST_SUB+=	ARM_ONLY=""
.else
PLIST_SUB+=	ARM_ONLY="@comment "
.endif

.if ${ARCH:Mmips*}
PLIST_SUB+=	MIPS_ONLY=""
.else
PLIST_SUB+=	MIPS_ONLY="@comment "
.endif

.if ${ARCH:Mpowerpc*}
PLIST_SUB+=	PPC_ONLY=""
.else
PLIST_SUB+=	PPC_ONLY="@comment "
.endif

.include <bsd.port.post.mk>
