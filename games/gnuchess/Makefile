# New ports collection makefile for:	Gnu Chess
# Date created:		04 July 1996
# Whom:			markm
#
# $FreeBSD$
#

PORTNAME=	gnuchess
PORTVERSION=	5.06
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	chess

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"Classic" Gnu Chess

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e 's|-D_THREAD_SAFE|${PTHREAD_CFLAGS:S/"//g}|g ; \
		 s|-pthread ||g' ${WRKSRC}/configure

post-install:
	${LN} -f ${PREFIX}/bin/gnuchess ${PREFIX}/bin/gnuchessx

.include <bsd.port.mk>
