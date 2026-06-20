PORTNAME=	gdb
PORTVERSION=	17.2
CATEGORIES=	devel
MASTER_SITES=	GNU
PKGNAMEPREFIX=	avr-

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	GNU GDB for the AVR target
WWW=		https://www.gnu.org/software/gdb/

LICENSE=	GPLv3

LIB_DEPENDS=	libexpat.so:textproc/expat2
LIB_DEPENDS+=	libxxhash.so:devel/xxhash
LIB_DEPENDS+=	libzstd.so:archivers/zstd
LIB_DEPENDS+=	libmpfr.so:math/mpfr
LIB_DEPENDS+=	libgmp.so:math/gmp

USES=		cpe gmake ncurses tar:xz iconv
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=avr --program-prefix=avr --disable-nls \
		--disable-werror \
		--with-gmp=${LOCALBASE} \
		--with-mpfr=${LOCALBASE} 

pre-configure:
	cd ${WRKSRC} ; ${RM} -r dejagnu expect tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.mk>
