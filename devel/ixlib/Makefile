# ex:ts=8
# New ports collection makefile for:	ixlib
# Date created:			Nov 1, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ixlib
PORTVERSION=	0.96.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small C++ tools library based on STL

USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" || ${OSVERSION} >= 500000
BROKEN=		"Does not compile on !i386 or on FreeBSD >= 5.x"
.endif

.include <bsd.port.post.mk>
