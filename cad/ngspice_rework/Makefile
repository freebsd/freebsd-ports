PORTNAME=	ngspice_rework
PORTVERSION=	44.2
CATEGORIES=	cad
MASTER_SITES=	SF/ngspice/ng-spice-rework/${PORTVERSION}
DISTNAME=	ngspice-${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Mixed-signal circuit simulator derived from Spice and Cider
WWW=		https://ngspice.sourceforge.io/

LICENSE=	BSD3CLAUSE BSD4CLAUSE LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfftw3.so:math/fftw3

FLAVORS=	x11 shlib
shlib_PKGNAMESUFFIX=		-shlib
shlib_PLIST=			${MASTERDIR}/pkg-plist-shlib

USES=		compiler:c11 gmake libtool ncurses readline autoreconf pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS_armv7=	--disable-openmp
# xspice, readline, osdi are now standard
CONFIGURE_ARGS=	--enable-cider \
		${CONFIGURE_ARGS_${ARCH}}
OPTIONS_DEFINE=	DEBUG

.if ${FLAVOR:U} ==	shlib
USE_LDCONFIG=		yes
CONFIGURE_ARGS+=	--with-ngshared --enable-shared
.else
USES+=			xorg
USE_XORG=		ice sm x11 xaw xext xmu xt xft
CONFIGURE_ARGS+=	--with-x
PLIST_FILES=		bin/ngspice share/man/man1/ngspice.1.gz
post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${RM} -r include lib share/ngspice && \
		${RM} bin/cmpp man/man1/cmpp.1
.endif

DEBUG_CONFIGURE_ENABLE=	debug

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
