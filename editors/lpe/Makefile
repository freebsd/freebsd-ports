# New ports collection makefile for:	lpe
# Date created:		12 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lpe
PORTVERSION=	1.2.6
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.sasknow.com/pub/ \
		ftp://ftp.twu.net/users/cdsmith/lpe/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ryan@sasknow.com
COMMENT=	A "lightweight programmer's editor" with syntax highlighting

LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib" \
		CPPFLAGS="-I${PREFIX}/include -I${LOCALBASE}/include" \
		LIBS="-ltermcap"
CONFIGURE_ARGS=	--includedir=${LOCALBASE}/include

MAN1=		lpe.1
MANLANG=	bg cs de es fr pl ru

.include <bsd.port.mk>
