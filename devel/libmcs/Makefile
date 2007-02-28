# New ports collection makefile for:	libmcs
# Date created:				27th February 2007
# Whom:					Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmcs
PORTVERSION=	0.4.0
CATEGORIES=	devel
MASTER_SITES=	http://sacredspiral.co.uk/~nenolod/mcs/
DISTNAME=	mcs-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	A BSD licenced configuration database system

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$$(LIBDIR)|$$(prefix)/libdata|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
