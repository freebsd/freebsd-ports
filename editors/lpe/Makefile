# New ports collection makefile for:	lpe
# Date created:		12 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lpe
PORTVERSION=	1.2.6
PORTREVISION=	6
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.sasknow.com/pub/ \
		ftp://ftp.twu.net/users/cdsmith/lpe/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	A "lightweight programmer's editor" with syntax highlighting

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2

MAKE_JOBS_UNSAFE=	yes

USE_AUTOTOOLS=	libtool:22
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib" \
		CPPFLAGS="-I${PREFIX}/include -I${LOCALBASE}/include" \
		LIBS="-ltermcap"
CONFIGURE_ARGS=	--includedir=${LOCALBASE}/include

MAN1=		lpe.1
MANLANG=	"" bg cs de es fr pl ru

.include <bsd.port.mk>
