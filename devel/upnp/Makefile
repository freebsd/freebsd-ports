# New ports collection makefile for:	upnp
# Date created:				02 August 2002
# Whom:	      				Yen-Ming Lee <leeym@leeym.com>
#
# $FreeBSD$
#

PORTNAME=	upnp
PORTVERSION=	1.2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Universal Plug and Play Software Development Kit

LIB_DEPENDS=	uuid.1:${PORTSDIR}/sysutils/e2fsprogs

USE_GMAKE=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/upnp
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
MAKEFILE=	makefile
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}
NOT_FOR_ARCHS=	sparc64
INSTALLS_SHLIB=	yes

post-patch:
	@${FIND} ${PATCH_WRKSRC} -name "*.[ch]" | \
		${XARGS} ${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,'
	@${FIND} ${PATCH_WRKSRC} -name "[Mm]akefile" | ${XARGS} ${REINPLACE_CMD} \
		-e 's,lpthread,pthread, ; s,/usr,,g ; s,1\.2\.1,1,g' \
		-e 's,MAKE = make,MAKE = ${GMAKE},' \
		-e 's,install bin,${INSTALL_PROGRAM} bin,g' \
		-e 's,install inc,${INSTALL_DATA} inc,g'
	@${REINPLACE_CMD} -e 's,MSG_NOSIGNAL,0,' ${PATCH_WRKSRC}/upnp/src/genlib/net/sock.c
	@${REINPLACE_CMD} -e 's,linux/if,net/if,' ${PATCH_WRKSRC}/upnp/src/api/upnpapi.c

.include <bsd.port.mk>
