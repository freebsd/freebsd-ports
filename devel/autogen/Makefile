# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	autogen
PORTVERSION=	5.18.4
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GNU/${PORTNAME}/rel${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool designed to simplify the creation and maintenance of programs

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libguile-2.0.so:lang/guile2

USES=		gmake libtool pathfix perl5 pkgconfig shebangfix tar:xz
USE_PERL5=	build
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libguile=yes --with-libxml2=yes \
		--datadir=${PREFIX}/share CONFIG_SHELL=${PREFIX}/bin/bash
USE_LDCONFIG=	yes
SHEBANG_FILES=	autoopts/tpl/*.pl
INSTALL_TARGET=	install-strip

INFO=		autogen

.include <bsd.port.mk>
