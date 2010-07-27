# New ports collection makefile for:	libzrtpcpp
# Date created:		2006-10-04
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libzrtpcpp
PORTVERSION=	1.4.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=ccrtp

MAINTAINER=	acm@FreeBSD.org
COMMENT=	ZRTP extension for GNU ccRTP

LIB_DEPENDS=	ccrtp1-1.7.0:${PORTSDIR}/devel/ccrtp \
		gcrypt.17:${PORTSDIR}/security/libgcrypt

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${OPENSSLINC}
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

post-patch:
	@cd ${WRKSRC}/src && \
		${FIND} * -type f -exec ${REINPLACE_CMD} -i "" -e "s|<malloc.h>|<stdlib.h>|g" "{}" \; && \
			${FIND} * -type f -exec ${REINPLACE_CMD} -i "" -e "s|<stdint.h>|<inttypes.h>|g" "{}" \;
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
