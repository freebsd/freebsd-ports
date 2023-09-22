PORTNAME=	emilua
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.3
CATEGORIES=	lang devel

MAINTAINER=	manipuladordedados@gmail.com
COMMENT=	Lua execution engine
WWW=		https://emilua.org

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	the software structures have not yet been ported

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor \
		boost-libs>0:devel/boost-libs \
		cmake:devel/cmake-core \
		gawk:lang/gawk \
		gperf:devel/gperf \
		re2c:devel/re2c \
		xxd:sysutils/xxd
LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libserd-0.so:devel/serd \
		libsord-0.so:devel/sord

USES=		localbase luajit:luajit-openresty meson ncurses pathfix \
		pkgconfig ssl
USE_GCC=	12
USE_GITHUB=	nodefault
GH_TUPLE=	BoostGSoC14:boost.http:93ae527c89ffc517862e1f5f54c8a257278f1195:emilua_http/subprojects/emilua-http \
		breese:trial.protocol:79149f6:trial_protocol/subprojects/trial-protocol
USE_GITLAB=	yes

MESON_ARGS=	--buildtype=plain \
		--wrap-mode=nodownload \
		-Db_pch=false \
		-Denable_http=true \
		-Denable_manpages=true \
		-Denable_tests=true

LDFLAGS+=	-static-libstdc++

post-extract:
	${CP} ${WRKSRC}/subprojects/packagefiles/emilua-http/meson.build \
		${WRKSRC}/subprojects/emilua-http/
	${CP} ${WRKSRC}/subprojects/packagefiles/trial.protocol/meson.build \
		${WRKSRC}/subprojects/trial-protocol/

post-install:
	${MV} ${STAGEDIR}${PREFIX}/man/man3em/* \
		${STAGEDIR}${PREFIX}/man/man3/
	${RMDIR} ${STAGEDIR}${PREFIX}/man/man3em

.include <bsd.port.mk>
