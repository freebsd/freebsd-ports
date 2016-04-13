# Created by: Peter Johnson <johnson.peter@gmail.com>
# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	2.17
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/binutils/releases
PKGNAMEPREFIX=	djgpp-

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	FSF binutils for DJGPP cross-development

LICENSE=	GPLv2

TARGET=		i586-pc-msdosdjgpp

USES=		gmake makeinfo tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_ARGS=	--target=${TARGET} \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--disable-nls --disable-shared --disable-werror

INFO=		as bfd binutils ld configure standards
INFO_PATH=	${TARGET}/info

BINARIES=	addr2line ar as c++filt ld nm objcopy objdump ranlib \
		readelf size strings strip

post-install:
.for F in ${BINARIES}
	@${LN} -f ${STAGEDIR}${PREFIX}/bin/${TARGET}-$F ${STAGEDIR}${PREFIX}/${TARGET}/bin/$F
.endfor
	@${RM} ${STAGEDIR}${PREFIX}/${TARGET}/info/dir

.include <bsd.port.mk>
