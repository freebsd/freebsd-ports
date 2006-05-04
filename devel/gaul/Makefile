# ex:ts=8
# Ports collection makefile for:	gaul
# Date created:			Oct 28, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gaul
PORTVERSION=	0.1849.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-devel-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Genetic Algorithm Utility Library

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -lcurses ${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread||g' ${WRKSRC}/configure

.include <bsd.port.mk>
