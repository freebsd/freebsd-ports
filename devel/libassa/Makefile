# ex:ts=8
# Ports collection makefile for:	libassa
# Date created:			Dec 24, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libassa
PORTVERSION=	3.4.2.2
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.([[:digit:]])$/-\1/}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	An C++ networking library and application framework

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_LDCONFIG=	yes
PLIST_SUB=	ASSA_VERSION=${PORTVERSION:R:R}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/(\.[[:digit:]])$//}

MAN1=		assa-genesis.1

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s: doc : :g' ${WRKSRC}/Makefile.in

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 500000 )
BROKEN=	compilation fails and passing -fhuge-objects does not help
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/debian/assa-genesis.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
