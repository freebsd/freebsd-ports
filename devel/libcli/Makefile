# New ports collection makefile for:	libcli
# Date created:		2011-04-27
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libcli
PORTVERSION=	1.9.4
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Emulates a cisco style command-line interface

LICENSE=	LGPL21

USE_GMAKE=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libcli.so \
		lib/libcli.so.1.9.4 \
		lib/libcli.so.1.9 \
		include/libcli.h

post-patch:
	@${REINPLACE_CMD} -e "/^OPTIM/d" \
		-e "/^DEBUG/d" \
		-e "s/gcc/${CC}/g" \
		-e "s/REVISION = 3/REVISION = 4/g" \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
