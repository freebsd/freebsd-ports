PORTNAME=	chez-scheme
PORTVERSION=	10.2.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	lang
MASTER_SITES=	https://github.com/cisco/ChezScheme/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
DISTNAME=	csv${PORTVERSION}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Chez Scheme system
WWW=		https://cisco.github.io/ChezScheme

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386 aarch64 armv7 powerpc

LIB_DEPENDS=	libuuid.so:misc/libuuid \
		libossp-uuid.so:misc/ossp-uuid

USES=		gmake iconv:lib ncurses

OPTIONS_DEFAULT=	X11
OPTIONS_DEFINE=	X11

HAS_CONFIGURE=	yes
ALL_TARGET=	build
CONFLICTS_INSTALL=	petite-chez
STRIP_FILES=	bin/petite bin/${PORTNAME} bin/${PORTNAME}-script
CHEZ_LIBDIR=	lib/${DISTNAME}
CFLAGS+=	-fPIC
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -luuid
CONFIGURE_ARGS=	--installprefix=${PREFIX} \
		--temproot=${STAGEDIR} \
		--installschemename=${PORTNAME} \
		--installscriptname=${PORTNAME}-script \
		--installman=${PREFIX}/share/man \
		--threads
PLIST_SUB=	PORTNAME=${PORTNAME} \
		CHEZ_ARCH=${CHEZ_ARCH} \
		CHEZ_LIBDIR=${CHEZ_LIBDIR}
X11_USES=	xorg
X11_USE=	XORG=x11

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
CHEZ_ARCH=	ta6fb
.elif (${ARCH} == "i386")
CHEZ_ARCH=	ti3fb
.elif (${ARCH} == "aarch64")
CHEZ_ARCH=	tarm64fb
.elif (${ARCH} == "armv7")
CHEZ_ARCH=	tarm32fb
.elif (${ARCH} == "powerpc")
CHEZ_ARCH=	tppc32fb
.endif

.if defined(NCURSES_RPATH)
NCURSES_REPL=	-e 's|-Wl,-rpath,${NCURSESRPATH}||g'
.else
NCURSES_REPL=
.endif

pre-configure:
	${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
		-e 's,/usr/local,${LOCALBASE},g' ${NCURSES_REPL} \
		-e 's,-liconv,${ICONV_LIB},g' ${WRKSRC}/configure

pre-build-X11-off:
	${ECHO_CMD} '#undef LIBX11' >>${WRKSRC}/c/version.h

post-install:
.for f in ${STRIP_FILES}
	@${CHMOD} +w ${STAGEDIR}${PREFIX}/${f}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${f}
	@${CHMOD} -w ${STAGEDIR}${PREFIX}/${f}
.endfor

.include <bsd.port.post.mk>
