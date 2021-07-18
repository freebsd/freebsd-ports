PORTNAME=	tagutil
PORTVERSION=	3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	alex@kaworu.ch
COMMENT=	Command line interface tool to manage tags in music files

LICENSE=	BSD2CLAUSE

BROKEN_riscv64=		fails to link: cannot open /nxb-bin/usr/lib/clang/11.0.0/lib/freebsd/libclang_rt.ubsan_standalone-riscv64.a: No such file or directory

LIB_DEPENDS=	libyaml.so:textproc/libyaml

USE_GITHUB=	yes
GH_ACCOUNT=	kAworu

USES=		cmake compiler:c++11-lang iconv pkgconfig
PLIST_FILES=	bin/tagutil \
		man/man1/tagutil.1.gz

CMAKE_ARGS=	-DMAN_PATH=${PREFIX}/man
CMAKE_SOURCE_PATH=	${WRKSRC}/src

OPTIONS_DEFINE=	JSON
OPTIONS_MULTI=	MEDIA
OPTIONS_MULTI_MEDIA=	FLAC OGG TAGLIB
OPTIONS_DEFAULT=	FLAC OGG TAGLIB
TAGLIB_DESC=	Multiple file format but limited tags support
JSON_DESC=	JSON output format support

JSON_LIB_DEPENDS=	libjansson.so:devel/jansson
JSON_CMAKE_OFF=	-DWITHOUT_JSON=yes
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CMAKE_OFF=	-DWITHOUT_FLAC=yes
OGG_LIB_DEPENDS=\
	libvorbisfile.so:audio/libvorbis \
	libogg.so:audio/libogg
OGG_CMAKE_OFF=	-DWITHOUT_OGGVORBIS=yes
TAGLIB_LIB_DEPENDS=	libtag_c.so:audio/taglib
TAGLIB_CMAKE_OFF=	-DWITHOUT_TAGLIB=yes
# For FreeBSD 11: ld: undefined reference to symbol `__cxa_demangle@@CXXABI_1.3' (try adding -lcxxrt)
.if exists(/usr/bin/ld.lld) && ${/usr/bin/ld:L:tA} != /usr/bin/ld.lld
TAGLIB_LDFLAGS=		-fuse-ld=lld
.endif

.include <bsd.port.mk>
