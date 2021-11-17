# Created by: AMAKAWA Shuhei <amakawa@jp.FreeBSD.org>

PORTNAME=	ngspice_rework
PORTVERSION=	35
CATEGORIES=	cad
MASTER_SITES=	SF/ngspice/ng-spice-rework/${PORTVERSION}
DISTNAME=	ngspice-${PORTVERSION}

MAINTAINER=	kevinz5000@gmail.com
COMMENT=	Mixed-signal circuit simulator derived from Spice and Cider

LICENSE=	BSD3CLAUSE BSD4CLAUSE LGPL21+
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	fails to link: missing sbrk

LIB_DEPENDS=	libfftw3.so:math/fftw3

FLAVORS=	x11 shlib
shlib_PKGNAMESUFFIX=		-shlib
shlib_PLIST=			${MASTERDIR}/pkg-plist-shlib

USES=		compiler:c11 gmake libtool ncurses readline autoreconf pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-cider --enable-xspice --with-readline=yes

OPTIONS_DEFINE=	DEBUG

.if ${FLAVOR:U} ==	shlib
USE_LDCONFIG=		yes
CONFIGURE_ARGS+=	--with-ngshared --enable-shared
.else
USES+=			xorg
USE_XORG=		ice sm x11 xaw xext xmu xt xft
CONFIGURE_ARGS+=	--with-x
PLIST_FILES=		bin/ngspice man/man1/ngspice.1.gz
post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${RM} -r include lib share && \
		${RM} bin/cmpp man/man1/cmpp.1
.endif

DEBUG_CONFIGURE_ENABLE=	debug

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
