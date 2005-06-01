# New ports collection makefile for:	libmorph
# Date Created:				14 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmorph
PORTVERSION=	0.1.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.winnicki.net/morpheus/meat/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for loading (and saving) 3d modeller object files

CONFLICTS=	xmorph*

USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
