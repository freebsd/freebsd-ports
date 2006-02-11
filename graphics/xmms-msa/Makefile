# New ports collection Makefile for:	xmms-msa
# Date created:				Feb 4, 2006
# Whom:					exprim
#
# $FreeBSD$
#

PORTNAME=	msa
PORTVERSION=	0.5.5
CATEGORIES=	graphics
MASTER_SITES=	http://republika.pl/kunik/msa/dl/
PKGNAMEPREFIX=	xmms-

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A spectrum analyzer with a skin support and some visualization modes

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_GMAKE=	yes
USE_X_PREFIX=	yes
MAKE_ARGS=	CC="${CC}" OPTS="${CFLAGS} -fPIC"
PLIST_FILES=	lib/xmms/Input/msa.so

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/xmms|${X11BASE}/share/xmms|' \
		${WRKSRC}/msa_config.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/msa.so ${PREFIX}/lib/xmms/Input

.include <bsd.port.mk>
