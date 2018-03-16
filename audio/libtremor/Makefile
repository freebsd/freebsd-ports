# Created by: kwm@rainbow-runner.nl
# $FreeBSD$

PORTNAME=	libtremor
PORTVERSION=	1.2.1.s20180316
CATEGORIES=	audio
MASTER_SITES=	http://git.xiph.org/?p=tremor.git;a=snapshot;sf=tgz;h=${GIT_COMMIT};/
DISTNAME=	${PORTNAME:S/lib//}-${GIT_COMMIT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Integer-only fully Ogg Vorbis compliant decoder library

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libogg.so:audio/libogg

GIT_COMMIT=	562307a
USES=		autoreconf libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
