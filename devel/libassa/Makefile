# ex:ts=8
# Ports collection makefile for:	libassa
# Date created:			Dec 24, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libassa
PORTVERSION=	3.4.1
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	An C++ networking library and application framework

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_LDCONFIG=	yes
PLIST_SUB=	ASSA_VERSION=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s: doc : :g' ${WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 500000 )
BROKEN=	compilation fails and passing -fhuge-objects does not help
.endif

.if ${ARCH} == "sparc64"
BROKEN=		does not build on sparc64
.endif

.include <bsd.port.post.mk>
