# New ports collection makefile for:	libzt
# Date created:        			09.06.2003
# Whom:               			Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	libzt
PORTVERSION=	1.0.2
CATEGORIES=	devel
MASTER_SITES=	http://www.zerotao.org/downloads/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of utility code for C application/server development

GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
USE_GETOPT_LONG=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile*" | ${XARGS} \
	${REINPLACE_CMD} -e \
		"s,^CFLAGS =,CFLAGS+=${CFLAGS},g ; \
		s,-no-cpp-precomp,,g"

.include <bsd.port.mk>
