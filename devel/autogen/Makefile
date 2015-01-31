# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	autogen
PORTVERSION=	5.18.4
CATEGORIES=	devel
MASTER_SITES=	GNU
MASTER_SITE_SUBDIR=	${PORTNAME}/rel${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT,gnu

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Automated Program Generator

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libguile-2.0.so:${PORTSDIR}/lang/guile2

USES=		gmake libtool pathfix perl5 pkgconfig shebangfix tar:xz
USE_PERL5=	build
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libguile=yes --with-libxml2=yes \
		--datadir=${PREFIX}/share
USE_LDCONFIG=	yes
SHEBANG_FILES=	autoopts/tpl/*.pl

INFO=	autogen

.include <bsd.port.mk>
