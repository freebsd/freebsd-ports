# New ports collection makefile for: mingw
# Date created:		6 June 2000
# Whom:			Toshihiro Inoue <tino@pa2.so-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	mingw
PORTVERSION=	2000.03.27
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tino@pa2.so-net.ne.jp

BUILD_DEPENDS=	i386-mingw32msvc-as:${PORTSDIR}/devel/mingw-binutils \
		mingwm10.dll:${PORTSDIR}/devel/mingw-bin-msvcrt
RUN_DEPENDS=	i386-mingw32msvc-gcc:${PORTSDIR}/devel/mingw-gcc

NO_BUILD=	yes

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
