# ex:ts=8
# Ports collection makefile for:	libvm68k
# Date created:			Jun 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libvm68k
PORTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.hypercore.co.jp/vx68k/${PORTNAME}-${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	M68000 virtual machine library

USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^#define _POSIX_C_SOURCE 199506L/d' \
		${WRKSRC}/memory.cc ${WRKSRC}/memory_map.cc ${WRKSRC}/version.cc
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir| ; \
		s|LTLIBRELEASE=".*"|LTLIBRELEASE=|' ${WRKSRC}/configure

.include <bsd.port.mk>
