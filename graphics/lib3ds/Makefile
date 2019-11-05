# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lib3ds
PORTVERSION=	1.3.0
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/lib3ds/ \
		http://pkgs.fedoraproject.org/repo/pkgs/lib3ds/${DISTNAME}${EXTRACT_SUFX}/2572f7b0f29b591d494c1a0658b35c86/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for handling 3DS (3D Studio) files

LICENSE=	LGPL21+

USES=		gl libtool localbase zip
GNU_CONFIGURE=	yes
USE_GL=		gl glu glut
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
