# New ports collection makefile for:	adns
# Date created:			Mon Mar 3, 2000
# Whom:				Kostya Lukin <lukin@okbmei.msk.su>
#
# $FreeBSD$
#

PORTNAME=	adns
PORTVERSION=	1.1
CATEGORIES=	dns
MASTER_SITES=	ftp://ftp.chiark.greenend.org.uk/users/ian/adns/
MASTER_SITE_SUBDIR=	adns

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy to use, asynchronous-capable DNS client library and utilities

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes

LIBVERSION=	1
PLIST_SUB+=	LIBVERSION="${LIBVERSION}"

post-install:
	@${LN} -sf libadns.so.${LIBVERSION} ${PREFIX}/lib/libadns.so
	${STRIP_CMD} ${PREFIX}/bin/adnslogres ${PREFIX}/bin/adnshost

.include <bsd.port.mk>
