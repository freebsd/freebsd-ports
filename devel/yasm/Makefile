# ex:ts=8
# Ports collection makefile for:	yasm
# Date created:			Apr 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yasm
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	devel lang
MASTER_SITES=	http://www.tortall.net/projects/yasm/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A complete rewrite of the NASM assembler

BUILD_DEPENDS=	re2c:${PORTSDIR}/devel/re2c
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_GETTEXT=	yes
USE_PERL5_BUILD=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
