PORTNAME=	autogen
PORTVERSION=	5.18.16
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	GNU/autogen/rel${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool designed to simplify the creation and maintenance of programs
WWW=		https://www.gnu.org/software/autogen/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS} \
		gmktemp:sysutils/coreutils
RUN_DEPENDS=	bash:shells/bash

USES=		gmake gnome guile:2.2 libtool pathfix perl5 pkgconfig shebangfix tar:xz
USE_GNOME=	libxml2
USE_PERL5=	build

BINARY_ALIAS=	mktemp=gmktemp
CONFIGURE_ARGS=	--datadir=${PREFIX}/share \
		--disable-dependency-tracking \
		--with-libguile=yes --with-libxml2=yes
CONFIGURE_ENV=	CONFIG_SHELL=${LOCALBASE}/bin/bash
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

INFO=		autogen

CONFLICTS_INSTALL=	columns # bin/columns

SHEBANG_FILES=	autoopts/tpl/*.pl

.include <bsd.port.mk>
