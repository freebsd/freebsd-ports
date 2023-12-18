PORTNAME=	lepton
PORTVERSION=	0.2022.04.13
CATEGORIES=	graphics devel

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Tool for manipulating files in LEP image format
WWW=		https://github.com/dropbox/lepton

LICENSE=	APACHE20

LIB_DEPENDS=	libbrotlienc.so:archivers/brotli

USES=		autoreconf localbase ssl shebangfix python:test
USE_GITHUB=	yes
GH_ACCOUNT=	dropbox
GH_TAGNAME=	429fe88

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-system-dependencies --disable-native-opt
TEST_TARGET=	check
SHEBANG_FILES=	test_suite/*.py
CFLAGS+=	-DBSD -DGIT_REVISION='\"${GH_TAGNAME}\"'	\
		-DUSE_SYSTEM_DEPENDENCIES -DUSE_SYSTEM_MD5_DEPENDENCY \
		-Wno-deprecated-declarations
.ifndef WITH_DEBUG
CFLAGS+=	-DNDEBUG
.endif
EXTRACT_AFTER_ARGS=--no-same-owner --no-same-permissions --exclude dependencies
PLIST_FILES=	bin/lepton

.if !${MACHINE_CPU:Mssse3}
IGNORE=	requires SSSE3 features in the processor
.else
CFLAGS+=	-mssse3
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lepton ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.pre.mk>

.if ${OPENSSLBASE} != /usr
LDFLAGS+=-L${OPENSSLLIB} ${OPENSSL_LDFLAGS}
CFLAGS+=-isystem ${OPENSSLINC}
.endif

.include <bsd.port.post.mk>
