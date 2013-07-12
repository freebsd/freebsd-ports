# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	ois
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/wgois/Source%20Release/1.2
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Object Oriented Input System

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		pathfix
USE_AUTOTOOLS=	libtool:env aclocal:env autoheader:env automake:env autoconf:env
USE_XORG=	x11 xaw
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} 's|^pkgconfigdir = .*|pkgconfigdir=$${prefix}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.am

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

.include <bsd.port.mk>
