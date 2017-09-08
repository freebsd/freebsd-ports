# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	autogen
PORTVERSION=	5.18.12
CATEGORIES=	devel
MASTER_SITES=	GNU/${PORTNAME}/rel${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool designed to simplify the creation and maintenance of programs

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libguile-2.0.so:lang/guile2
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFIGURE_ARGS=	--datadir=${PREFIX}/share --with-libguile=yes --with-libxml2=yes
CONFIGURE_ENV=	CONFIG_SHELL=${LOCALBASE}/bin/bash
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
USE_PERL5=	build
USES=		gmake gnome libtool pathfix perl5 pkgconfig shebangfix tar:xz

INFO=		autogen

SHEBANG_FILES=	autoopts/tpl/*.pl

.include <bsd.port.mk>
