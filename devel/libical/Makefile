# New ports collection makefile for:   libical
# Date created:        8 November 2002
# Whom:                Joe Kelsey
#
# $FreeBSD$
#

PORTNAME=	libical
PORTVERSION=	0.44
CATEGORIES=	devel
MASTER_SITES=	SF/freeassociation/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@freebsd.org
COMMENT=	An implementation of the IETF's Calendaring and Scheduling protocols

USE_GNOME=	gnomehack
USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_LDCONFIG=	yes
CONFIGURE_ENV+= CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

.if !defined(WITHOUT_PYTHON)
CONFIGURE_ARGS=	--enable-python=yes
USE_PYTHON=	yes
.else
CONFIGURE_ARGS=	--enable-python=no
.endif

.include <bsd.port.pre.mk>
.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -fPIC"
.endif

.include <bsd.port.post.mk>
