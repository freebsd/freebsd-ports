# Created by: Jerry A! <jerry@thehutt.org>
# $FreeBSD$

PORTNAME=	libstroke
PORTVERSION=	0.5.1
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://etla.net/libstroke/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stroke translation library

USES=		gmake
USE_CSTD=	gnu89
USE_XORG=	x11
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-gtktest

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
			${WRKSRC}/configure

.include <bsd.port.mk>
