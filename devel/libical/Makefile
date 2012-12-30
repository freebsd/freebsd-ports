# Created by: Joe Kelsey
# $FreeBSD$

PORTNAME=	libical
PORTVERSION=	0.48
CATEGORIES=	devel
MASTER_SITES=	SF/freeassociation/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An implementation of the IETF Calendaring and Scheduling protocols

USE_GNOME=	gnomehack ltverhack
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	PYTHON

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS=	--enable-python=yes
USE_PYTHON=	yes
.else
CONFIGURE_ARGS=	--enable-python=no
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
