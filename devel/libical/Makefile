# Created by: Joe Kelsey
# $FreeBSD$

PORTNAME=	libical
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	SF/freeassociation/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the IETF Calendaring and Scheduling protocols

LICENSE_COMB=	dual
LICENSE=	MPL LGPL21

USES=		cmake gmake pathfix perl5
USE_PERL5=	build
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libical*.so.1.0.0

.include <bsd.port.post.mk>
