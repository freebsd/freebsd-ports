# New ports collection makefile for:	librelp
# Date created:		1 April 2008
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	librelp
PORTVERSION=	0.1.1
CATEGORIES=	devel
MASTER_SITES=	CENKES http://download.rsyslog.com/librelp/

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Reliable event logging protocol library

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
PLIST_FILES=	include/${PORTNAME}.h lib/${PORTNAME}.so lib/${PORTNAME}.so.0 \
		lib/${PORTNAME}.la libdata/pkgconfig/relp.pc
PORT_VERBS=	relp

post-patch:
	@${REINPLACE_CMD} -e '/^pkgconfigdir =/s|=.*| \
		= ${PREFIX}/libdata/pkgconfig|' ${WRKSRC}/Makefile.in
	@${ECHO_CMD} "#include <sys/types.h>" >> ${WRKSRC}/src/relp.h

.include <bsd.port.mk>
