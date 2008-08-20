# New ports collection makefile for:	ois
# Date created:		16 Jun 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	ois
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	wgois
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Object Oriented Input System

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_AUTOTOOLS=	libtool:15:env aclocal:19:env autoheader:262:env automake:19:env autoconf:262:env
USE_XORG=	x11 xaw
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} 's|^pkgconfigdir = .*|pkgconfigdir=$${prefix}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.am

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
