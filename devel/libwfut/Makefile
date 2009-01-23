# New ports collection makefile for:	libwfut
# Date created:				4th April 2007
# Whom:					Oliver Lehmann
#
# $FreeBSD$
#

PORTNAME=	libwfut
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	worldforge

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	WorldForge update library

LIB_DEPENDS=	sigc-2.0:${PORTSDIR}/devel/libsigc++20 \
		curl.5:${PORTSDIR}/ftp/curl

CONFIGURE_ARGS+=--without-python
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
MAN1=		wfut.1

post-patch:
	@${REINPLACE_CMD} -e 's/ python//g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
