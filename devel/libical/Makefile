# Created by: Joe Kelsey
# $FreeBSD$

PORTNAME=	libical
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Implementation of the IETF Calendaring and Scheduling protocols

LICENSE=	LGPL21 MPL10
LICENSE_COMB=	dual

LIB_DEPENDS=	libicuuc.so:devel/icu

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
