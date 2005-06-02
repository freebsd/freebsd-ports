# New ports collection makefile for:	cim
# Date created:			21 Sept 1996
# Whom:				giffunip
#
# $FreeBSD$
#

PORTNAME=	cim
PORTVERSION=	3.36
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/cim/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compiler for the SIMULA programming language

USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
MAN1=		cim.1

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
