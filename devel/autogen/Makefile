# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	autogen
PORTVERSION=	5.18.16
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU/${PORTNAME}/rel${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool designed to simplify the creation and maintenance of programs

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS} \
		gmktemp:sysutils/coreutils
LIB_DEPENDS=	libguile-2.2.so:lang/guile2
RUN_DEPENDS=	bash:shells/bash

# bin/columns
CONFLICTS_INSTALL=	columns

USES=		gmake gnome libtool pathfix perl5 pkgconfig shebangfix tar:xz
USE_GNOME=	libxml2
USE_PERL5=	build

CONFIGURE_ARGS=	--datadir=${PREFIX}/share \
		--disable-dependency-tracking \
		--with-libguile=yes --with-libxml2=yes
CONFIGURE_ENV=	CONFIG_SHELL=${LOCALBASE}/bin/bash
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

INFO=		autogen

SHEBANG_FILES=	autoopts/tpl/*.pl

.include <bsd.port.mk>
