# New ports collection makefile for:	liblogging
# Date created:		9 July 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	liblogging
PORTVERSION=	0.6.0
CATEGORIES=	devel
MASTER_SITES=	SF http://download.adiscon.com/

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Easy to use system logging library

USE_DOS2UNIX=	yes
USE_LDCONFIG=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/src
MAKEFILE=	makefile
CFLAGS+=	-fPIC
PLIST_FILES=	include/${PORTNAME}.h include/${PORTNAME}-config.h include/srAPI.h \
		include/syslogmessage.h lib/${PORTNAME}.so lib/${PORTNAME}.so.0

post-extract:
	@${MV} ${WRKSRC}/config.h ${WRKSRC}/${PORTNAME}-config.h

post-patch:
	@${REINPLACE_CMD} -e 's|config\.h|${PORTNAME}-config.h|' ${WRKSRC}/*.[ch] \
		${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|\.a|.so|g;s|[(]AR[)] cru|{CC} ${CFLAGS} -shared -o|'\
		${WRKSRC}/${MAKEFILE}

do-install:
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTNAME}.h ${PORTNAME}-config.h \
		srAPI.h syslogmessage.h ${PREFIX}/include/
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}.so ${PREFIX}/lib/
	@${LN} -sf ${PORTNAME}.so ${PREFIX}/lib/${PORTNAME}.so.0

.include <bsd.port.mk>
