# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lib3ds
PORTVERSION=	1.3.0
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://pkgs.fedoraproject.org/repo/pkgs/lib3ds/lib3ds-1.3.0.zip/2572f7b0f29b591d494c1a0658b35c86/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for handling 3DS (3D Studio) files

LICENSE=	LGPL21+

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool zip
USE_GL=		glut
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.mk>
