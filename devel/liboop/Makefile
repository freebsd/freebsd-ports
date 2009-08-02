# ex:ts=8
# New ports collection makefile for:	liboop
# Date created:			Jun 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	liboop
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A low-level event loop management library for POSIX-based OS

LIB_DEPENDS=	adns.1:${PORTSDIR}/dns/adns \
		tcl84.1:${PORTSDIR}/lang/tcl84 \
		wwwcore.1:${PORTSDIR}/www/libwww

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GNOME=	glib12 glib20 gnomehack gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-libwww
USE_LDCONFIG=	yes

CPPFLAGS=	-I${LOCALBASE}/include/tcl8.4 -I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|8\.4|84|g' ${WRKSRC}/configure

.include <bsd.port.mk>
