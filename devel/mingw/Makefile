# New ports collection makefile for: mingw
# Date created:		6 June 2000
# Whom:			Toshihiro Inoue <tino@pa2.so-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	mingw
PORTVERSION=	20011229
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	doc@hisio.safenet.pl

RUN_DEPENDS=	i386-mingw32msvc-as:${PORTSDIR}/devel/mingw-binutils \
		mingwm10.dll:${PORTSDIR}/devel/mingw-bin-msvcrt \
		i386-mingw32msvc-gcc:${PORTSDIR}/devel/mingw-gcc
.if !defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	${LOCALBASE}/i386-mingw32msvc/include/GL/gl.h:${PORTSDIR}/devel/mingw-opengl-headers
.endif

NO_BUILD=	yes

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
