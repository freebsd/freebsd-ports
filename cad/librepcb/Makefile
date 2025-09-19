PORTNAME=	librepcb
DISTVERSION=	1.3.0
DISTVERSIONSUFFIX=	-source
CATEGORIES=	cad
#MASTER_SITES=	https://download.librepcb.org/releases/${DISTVERSION}/
MASTER_SITES=	LOCAL/yuri:main # .zip archive repackaged as .tar.gz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Schematic and PCB editing software
WWW=		https://librepcb.org/ \
		https://github.com/LibrePCB/LibrePCB/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg4 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreeimage.so:graphics/freeimage \
		libfreetype.so:print/freetype2 \
		libtbb.so:devel/onetbb \
		libTKService.so:cad/opencascade

USES=		cargo cmake:testing compiler:c++17-lang desktop-file-utils gl \
		localbase:ldflags qt:6 shared-mime-info xorg #zip
USE_QT=		base declarative svg tools:build
USE_GL=		gl glu
USE_XORG=	x11

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

MAKE_ENV+=	${WRK_ENV} ${CARGO_ENV}

#DISTFILES+=	librepcb-1.3.0-source.zip:main
DISTFILES+=	librepcb-1.3.0-source.tar.gz:main # .zip archive repackaged as .tar.gz

CARGO_SRC_SUBDIR=	libs/librepcb/rust-core # Rust sub-project
CARGO_CRATES=	adler2-2.0.0 \
		aho-corasick-1.1.3 \
		anstream-0.6.18 \
		anstyle-1.0.10 \
		anstyle-parse-0.2.6 \
		anstyle-query-1.1.2 \
		anstyle-wincon-3.0.6 \
		anyhow-1.0.94 \
		bitflags-2.6.0 \
		byteorder-1.5.0 \
		cbindgen-0.27.0 \
		cfg-if-1.0.0 \
		clap-4.5.22 \
		clap_builder-4.5.22 \
		clap_lex-0.7.3 \
		colorchoice-1.0.3 \
		crc32fast-1.4.2 \
		crossbeam-utils-0.8.20 \
		deranged-0.3.11 \
		equivalent-1.0.1 \
		errno-0.3.10 \
		fastrand-2.2.0 \
		flate2-1.0.35 \
		hashbrown-0.15.2 \
		heck-0.4.1 \
		indexmap-2.7.0 \
		interactive-html-bom-0.2.0 \
		is_terminal_polyfill-1.70.1 \
		itoa-1.0.14 \
		jzon-0.12.5 \
		libc-0.2.167 \
		linux-raw-sys-0.4.14 \
		log-0.4.22 \
		lz-str-0.2.1 \
		memchr-2.7.4 \
		miniz_oxide-0.8.0 \
		num-conv-0.1.0 \
		once_cell-1.20.2 \
		parameterized_test-0.2.1 \
		powerfmt-0.2.0 \
		proc-macro2-1.0.92 \
		quote-1.0.37 \
		regex-1.11.1 \
		regex-automata-0.4.9 \
		regex-syntax-0.8.5 \
		rustix-0.38.41 \
		ryu-1.0.18 \
		serde-1.0.215 \
		serde_derive-1.0.215 \
		serde_json-1.0.133 \
		serde_spanned-0.6.8 \
		strsim-0.11.1 \
		syn-2.0.90 \
		tempfile-3.14.0 \
		time-0.3.37 \
		time-core-0.1.2 \
		toml-0.8.19 \
		toml_datetime-0.6.8 \
		toml_edit-0.22.22 \
		unicode-ident-1.0.14 \
		utf8parse-0.2.2 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		winnow-0.6.20 \
		zip-0.6.6

CMAKE_ARGS=		-DFREEBSD_CARGO_ENV=${CARGO_ENV}
CMAKE_ARGS+=		-DCMAKE_PREFIX_PATH=${LOCALBASE}/lib # workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=274834
CMAKE_OFF=		BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS
CMAKE_TESTING_TARGET=

post-test: # run tests
	@${BUILD_WRKSRC}/tests/unittests/librepcb-unittests

.include <bsd.port.mk>
