# Created by: Joe Kelsey
# $FreeBSD$

PORTNAME=	libical
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the IETF Calendaring and Scheduling protocols

LICENSE_COMB=	dual
LICENSE=	MPL LGPL21

USE_GITHUB=	yes

USES=		cmake pathfix perl5
USE_PERL5=	build
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE= yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
