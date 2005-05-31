# New ports collection makefile for:	libstroke
# Date created:				31 December 2001
# Whom:					Jerry A! <jerry@thehutt.org>
#
# $FreeBSD$
#

PORTNAME=	libstroke
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.etla.net/libstroke/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A stroke translation library

USE_XLIB=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
.include <bsd.port.mk>
