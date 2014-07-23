# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	ois
PORTVERSION=	1.2.0
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF/wgois/Source%20Release/1.2
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Object Oriented Input System

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		pathfix gmake libtool
PATHFIX_MAKEFILEIN=	Makefile.am
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize
AUTOMAKE_ARGS=	--add-missing --copy --foreign
USE_XORG=	x11 xaw
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
