# Created by: Tony Maher
# $FreeBSD$

PORTNAME=	mummer
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.0beta2-2
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g277dac5
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modular system for rapid whole genome alignment

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	yaggo:devel/yaggo

USES=		autoreconf compiler:c++11-lang gmake libtool perl5 shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}4
USE_LDCONFIG=	yes

SHEBANG_FILES=	scripts/*.pl
perl_OLD_CMD=	__PERL_PATH
_SHEBANG_REINPLACE_ARGS+=	-e "s|__BIN_DIR|${PREFIX}/bin|g;s|__AUX_BIN_DIR|${PREFIX}/libexec/mummer|g;s|__SCRIPT_DIR|${PREFIX}/libexec/mummer|g"

.include <bsd.port.mk>
