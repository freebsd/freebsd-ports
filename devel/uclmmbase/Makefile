# New ports collection makefile for:	uclmmbase
# Version required:			1.1.2
# Date created:				Thanksgiving Day, 1999
# Whom:	      				Garrett Wollman <wollman@lcs.mit.edu>
#
# $FreeBSD$
#

DISTNAME=	common-1.1.2
PKGNAME=	uclmmbase-1.1.2
CATEGORIES=	devel
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/common/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/common
GNU_CONFIGURE=	yes

RESTRICTED=	"Contains DES cryptography."

INSTALL_HDRS=	base64.h config_win32.h config_unix.h crypt_random.h \
		debug.h hmac.h mbus.h md5.h memory.h net_udp.h qfDES.h \
		rtp.h util.h version.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/libuclmmbase.a ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/uclmmbase
.for file in ${INSTALL_HDRS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include/uclmmbase
.endfor

.include <bsd.port.mk>
