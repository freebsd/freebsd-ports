# ex:ts=8
# New ports collection makefile for:	ixlib
# Date created:			Nov 1, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ixlib
PORTVERSION=	0.96.2
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small C++ tools library based on STL

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
MAKE_ENV+=	SED="sed"
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

pre-configure:
	${CP} ${LTMAIN} ${WRKSRC}

.include <bsd.port.post.mk>
