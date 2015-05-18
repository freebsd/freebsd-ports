# $FreeBSD$

PORTNAME=	qqwing
PORTVERSION=	1.3.3
DISTVERSIONPREFIX=	v
CATEGORIES=	games gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Sudoku generating and solving software

BUILD_DEPENDS=	automake>=0:${PORTSDIR}/devel/automake \
		autoconf>=0:${PORTSDIR}/devel/autoconf \
		libtool:${PORTSDIR}/devel/libtool

USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	glib20 introspection:build
USE_GITHUB=	yes
GH_ACCOUNT=	stephenostermiller
USE_LDCONFIG=	yes
CONFIGURE_ENV+=	CC=cc CXX=c++ CPP=cpp

post-patch:
	@${REINPLACE_CMD} -e 's|exit 1|exit 0|g' \
		${WRKSRC}/build/not_root_check.sh

	@${REINPLACE_CMD} -e 's|touch --date 1980-01-01|touch |g' \
	       	${WRKSRC}/build/*.sh

	@${REINPLACE_CMD} -e 's|sudo||g' \
	       	${WRKSRC}/build/cpp_install.sh

do-build:
	@(cd ${WRKSRC} && ${SH} build/cpp_configure.sh && ${SH} build/cpp_compile.sh && ${SH} build/cpp_dist.sh)

do-install:
	@(cd ${WRKSRC}/target/automake/.libs && ${CP} libqqwing.so.2 ${STAGEDIR}${PREFIX}/lib)
	@(${LN} -fs ${PREFIX}/lib/libqqwing.so.2 ${STAGEDIR}${PREFIX}/lib/libqqwing.so.2.0.3)
	@(${LN} -fs ${PREFIX}/lib/libqqwing.so.2 ${STAGEDIR}${PREFIX}/lib/libqqwing.so)
	@(cd ${WRKSRC}/target/automake/ && ${CP} qqwing.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig)
	@(cd ${WRKSRC}/target/automake/ && ${CP} qqwing.hpp ${STAGEDIR}${PREFIX}/include)
	@(cd ${WRKSRC}/target/automake/ && ${CP} qqwing ${STAGEDIR}${PREFIX}/bin)
	@(cd ${WRKSRC}/target/automake/ && ${GZIP_CMD} qqwing.1 && ${CP} qqwing.1.gz ${STAGEDIR}${PREFIX}/man/man1/)

.include <bsd.port.mk>
