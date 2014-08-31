# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	autogen
PORTVERSION=	5.12
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	GNU
MASTER_SITE_SUBDIR=	${PORTNAME}/rel${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT,gnu

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	The Automated Program Generator

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libguile.so:${PORTSDIR}/lang/guile

USES=		gmake libtool pathfix shebangfix tar:bzip2
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libguile=yes --with-libxml2=yes --datadir=${PREFIX}/share
USE_LDCONFIG=	yes
SHEBANG_FILES=	autoopts/tpl/*.pl

INFO=	autogen

.include <bsd.port.mk>
