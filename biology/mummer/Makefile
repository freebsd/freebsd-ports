PORTNAME=	mummer
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.1
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modular system for rapid whole genome alignment
WWW=		https://mummer.sourceforge.net/ \
		https://github.com/mummer4/mummer

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	yaggo:devel/yaggo

USES=		autoreconf compiler:c++17-lang gmake libtool perl5 shebangfix
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}4

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip

SHEBANG_FILES=	scripts/*.pl
perl_OLD_CMD=	__PERL_PATH
_SHEBANG_REINPLACE_ARGS+=	-e "s|__BIN_DIR|${PREFIX}/bin|g;s|__AUX_BIN_DIR|${PREFIX}/libexec/mummer|g;s|__SCRIPT_DIR|${PREFIX}/libexec/mummer|g"

TEST_TARGET=	check

post-install:
	# fix conflict with libgd
	@${MV} ${STAGEDIR}${PREFIX}/bin/annotate ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-annotate

# tests as of 4.0.1, see https://github.com/mummer4/mummer/issues/224:
# TOTAL: 9
# PASS:  3
# SKIP:  0
# XFAIL: 0
# FAIL:  6
# XPASS: 0
# ERROR: 0

.include <bsd.port.mk>
