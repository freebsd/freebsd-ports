# ex:ts=8
# Ports collection makefile for:	libnova
# Date created:			Oct 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libnova
PORTVERSION=	0.11.0
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Astronomical Calculation Library

USE_GNOME=	gnometarget lthack
GNU_CONFIGURE=  yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=		requires FreeBSD 5.3 or higher
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
