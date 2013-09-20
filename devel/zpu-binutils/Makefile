# $FreeBSD$

PORTNAME=	zpu-binutils
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	zpu-toolchain-${PORTVERSION}

MAINTAINER=	db@FreeBSD.org
COMMENT=	ZPU toolchain

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/toolchain

USES=		gettext
MANPREFIX=	${PREFIX}/zpu
MANCOMPRESSED=	no
MAN1=		zpu-elf-addr2line.1 zpu-elf-ar.1 zpu-elf-dlltool.1 \
		zpu-elf-nlmconv.1 zpu-elf-nm.1 zpu-elf-objcopy.1 \
		zpu-elf-objdump.1 zpu-elf-ranlib.1 zpu-elf-size.1 \
		zpu-elf-strings.1 zpu-elf-strip.1 zpu-elf-windres.1 \
		zpu-elf-c++filt.1 zpu-elf-as.1 zpu-elf-ld.1 zpu-elf-readelf.1

INFO=		zpu/as zpu/bfd zpu/binutils zpu/configure zpu/ld zpu/standards

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's/%%CC%%/${CC}/' ${WRKSRC}/build.sh
	${CP}	${FILESDIR}/install.sh ${WRKSRC}
	@${REINPLACE_CMD} -e 's/%%GMAKE%%/${GMAKE}/' ${WRKSRC}/build.sh \
		${WRKSRC}/install.sh
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/build.sh

do-install:
	cd ${WRKSRC} && ${SH} install.sh

do-build:
	cd ${WRKSRC} && ${SH} build.sh

.include <bsd.port.mk>
