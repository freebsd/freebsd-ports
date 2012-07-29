# New ports collection makefile for:	libmorph
# Date Created:				14 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmorph
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.winnicki.net/morpheus/meat/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for loading (and saving) 3D modeller object files

CONFLICTS=	xmorph*

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
