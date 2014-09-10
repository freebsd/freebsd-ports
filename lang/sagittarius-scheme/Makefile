# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sagittarius
PORTVERSION=	0.5.7
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://distfiles.pirateparty.in/%SUBDIR%/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ashish
PKGNAMESUFFIX=	-scheme

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	R6RS/R7RS Scheme system

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/Copyright

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/libffi.pc:${PORTSDIR}/devel/libffi
LIB_DEPENDS=	libffi.so:${PORTSDIR}/devel/libffi \
		libgc-threaded.so:${PORTSDIR}/devel/boehm-gc-threaded

USES=		cmake gmake
ONLY_FOR_ARCHS=	amd64 i386
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	ODBC

CMAKE_ARGS+=	-DINSTALL_PREFIX=${PREFIX}

PLIST_SUB=	PORTNAME=sagittarius PORTVERSION=${PORTVERSION}

ODBC_LIB_DEPENDS=	libiodbc.so:${PORTSDIR}/databases/libiodbc
OPTIONS_SUB=		ODBC

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MODBC}
post-patch:
	@${REINPLACE_CMD} -e '/odbc odbc/d' ${WRKSRC}/ext/CMakeLists.txt
.endif

.include <bsd.port.pre.mk>

.if ${ARCH}=="i386"
PLIST_ARCH=	i386
USE_GCC=	yes
.else
PLIST_ARCH=	x86_64
.endif

PLIST_SUB+=	PLIST_ARCH=${PLIST_ARCH}

post-install:
	@${LN} -sf ${PREFIX}/bin/sagittarius ${STAGEDIR}${PREFIX}/bin/sash

post-build:
	@${GMAKE} -C ${WRKSRC} doc

.include <bsd.port.post.mk>
