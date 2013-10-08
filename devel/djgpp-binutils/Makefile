# Created by: Peter Johnson <johnson.peter@gmail.com>
# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	2.17
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	djgpp-

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	FSF binutils for DJGPP cross-development

LICENSE=	GPLv2

TARGET=		i586-pc-msdosdjgpp

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure

USE_BZIP2=	yes
USES=	gmake
GNU_CONFIGURE=	yes
SRCDIR=		${WRKDIR}/binutils-${PORTVERSION}
WRKSRC=		${WRKDIR}/build
CONFIGURE_ARGS=	--target=${TARGET} \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--disable-nls --disable-shared --disable-werror

INFO=		as bfd binutils ld configure standards
INFO_PATH=	${TARGET}/info

BINARIES=	addr2line ar as c++filt ld nm objcopy objdump ranlib \
		readelf size strings strip

pre-configure:
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-install:
.for F in ${BINARIES}
	@${LN} -f ${STAGEDIR}${PREFIX}/bin/${TARGET}-$F ${STAGEDIR}${PREFIX}/${TARGET}/bin/$F
.endfor
	@${RM} ${STAGEDIR}${PREFIX}/${TARGET}/info/dir

.include <bsd.port.mk>
