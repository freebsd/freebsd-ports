# New ports collection makefile for:	libzrtpcpp
# Date created:		2006-10-04
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libzrtpcpp
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=ccrtp

MAINTAINER=	acm@FreeBSD.org
COMMENT=	ZRTP extension for GNU ccRTP

LIB_DEPENDS=	ccrtp1-1.5.0:${PORTSDIR}/devel/ccrtp

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GCC=	3.4+
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

post-patch:
	@cd ${WRKSRC}/src && \
		${FIND} * -type f -exec ${REINPLACE_CMD} -i "" -e "s|<malloc.h>|<stdlib.h>|g" "{}" \; && \
			${FIND} * -type f -exec ${REINPLACE_CMD} -i "" -e "s|<stdint.h>|<inttypes.h>|g" "{}" \;
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
