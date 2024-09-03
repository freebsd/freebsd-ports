PORTNAME=	emilua
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.1
CATEGORIES=	lang devel

MAINTAINER=	manipuladordedados@gmail.com
COMMENT=	Lua execution engine
WWW=		https://emilua.org/

LICENSE=	BSL MIT
LICENSE_COMB=	dual
LICENSE_FILE_BSL=	${WRKSRC}/LICENSE-BSL-1.0.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT.txt

IGNORE_FreeBSD_13=	not supported by Emilua

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor \
		boost-libs>0:devel/boost-libs \
		cereal>0:devel/cereal \
		cmake:devel/cmake-core \
		gawk:lang/gawk \
		gperf:devel/gperf \
		ksh93:shells/ksh \
		re2c:devel/re2c

LIB_DEPENDS=	libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libfmt.so:devel/libfmt

USES=		localbase luajit:luajit-devel meson ncurses pathfix \
		pkgconfig ssl
USE_GITHUB=	nodefault
GH_TUPLE=	breese:trial.protocol:79149f6:trial_protocol/subprojects/trial-protocol \
		chriskohlhoff:asio:c586e95:asio/subprojects/asio
USE_GITLAB=	yes

CONFIGURE_ENV+=	BOOST_INCLUDEDIR="${LOCALBASE}/include" \
		BOOST_LIBRARYDIR="${LOCALBASE}/lib"

MESON_ARGS=	--buildtype=plain \
		--wrap-mode=nodownload \
		-Db_pch=false \
		-Denable_manpages=true \
		-Denable_tests=true \
		-Duse_standalone_asio=true

post-extract:
	${CP} ${WRKSRC}/subprojects/packagefiles/trial.protocol/meson.build \
		${WRKSRC}/subprojects/trial-protocol/

.include <bsd.port.mk>
