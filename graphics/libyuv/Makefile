# Created by: Corey Smith <corsmith@gmail.com>
# $FreeBSD$

PORTNAME=	libyuv
DISTVERSION=	0.0.1280
CATEGORIES=	graphics
MASTER_SITES=	http://files.freeswitch.org/downloads/libs/

MAINTAINER=	corsmith@gmail.com
COMMENT=	Library for freeswitch yuv graphics manipulation

LICENSE=	BSD3CLAUSE

MAKE_JOBS_UNSAFE=	yes
CXXFLAGS+=		-fPIC
USE_LDCONFIG=		yes

BROKEN_aarch64=		Fails to compile: undefined reference to SplitUVRow_NEON

.include <bsd.port.mk>
