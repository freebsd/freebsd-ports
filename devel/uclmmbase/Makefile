# New ports collection makefile for:	uclmmbase
# Version required:			1.0.9
# Date created:				Thanksgiving Day, 1999
# Whom:	      				Garrett Wollman <wollman@lcs.mit.edu>
#
# $FreeBSD$
#

DISTNAME=	common-1.0.9
PKGNAME=	uclmmbase-1.0.9
CATEGORIES=	devel
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/common/

WRKSRC=		${WRKDIR}/common
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

RESTRICTED=	"Contains DES cryptography."

INSTALL_HDRS=	base64.h config_win32.h config_unix.h crypt_random.h \
		debug.h hmac.h mbus.h md5.h memory.h net_udp.h qfDES.h \
		rtp.h util.h version.h

do-install:
	cd ${WRKSRC}; \
	${INSTALL} -c -o root -g wheel -m 444 libcommon.a \
		${PREFIX}/lib/libuclmmbase.a; \
	${MKDIR} ${PREFIX}/include/uclmmbase; \
	${INSTALL_DATA} ${INSTALL_HDRS} ${PREFIX}/include/uclmmbase

.include <bsd.port.mk>
