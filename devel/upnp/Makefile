# New ports collection makefile for:	upnp
# Date created:				02 August 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	upnp
PORTVERSION=	1.0.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}sdk-${PORTVERSION}

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Universal Plug and Play Software Development Kit

LIB_DEPENDS=	uuid.1:${PORTSDIR}/sysutils/e2fsprogs

USE_GMAKE=	yes
USE_REINPLACE=	yes
MAKEFILE=	makefile
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}
NOT_FOR_ARCHS=	sparc64
INSTALLS_SHLIB=	yes

post-patch:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,MAKE = make,MAKE = ${GMAKE},' \
		src/genlib/makefile src/makefile
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' \
		src/inc/genlib/client_table/client_table.h \
		src/inc/genlib/http_client/http_client.h \
		src/inc/genlib/service_table/service_table.h \
		src/inc/genlib/timer_thread/timer_thread.h \
		src/upnpdom/domCif.cpp
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,MSG_NOSIGNAL,0,' \
		src/genlib/http_client/http_client.c \
		src/genlib/net/http/readwrite.cpp

.include <bsd.port.mk>
