# New ports collection makefile for:	uclmmbase
# Date created:				Thanksgiving Day, 1999
# Whom:	      				Garrett Wollman <wollman@lcs.mit.edu>
#
# $FreeBSD$
#

PORTNAME=	uclmmbase
PORTVERSION=	1.2.8
CATEGORIES=	devel ipv6
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/common/
DISTNAME=	common-${PORTVERSION}

MAINTAINER=	fenner@FreeBSD.org

WRKSRC=		${WRKDIR}/common
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ipv6
.endif

RESTRICTED=	"Contains DES cryptography."

INSTALL_HDRS=	base64.h config_win32.h config_unix.h crypt_random.h \
		debug.h hmac.h mbus.h md5.h memory.h net_udp.h qfDES.h \
		rtp.h uclconf.h util.h version.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libuclmmbase.a ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/uclmmbase
.for file in ${INSTALL_HDRS}
	${INSTALL_DATA} ${WRKSRC}/src/${file} ${PREFIX}/include/uclmmbase
.endfor

.include <bsd.port.post.mk>
