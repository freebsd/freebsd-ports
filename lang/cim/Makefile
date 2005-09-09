# New ports collection makefile for:	cim
# Date created:			21 Sept 1996
# Whom:				giffunip
#
# $FreeBSD$
#

PORTNAME=	cim
PORTVERSION=	3.37
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/cim/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compiler for the SIMULA programming language

USE_PERL5=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

MAN1=		cim.1
INFO=		cim

.include <bsd.port.mk>
