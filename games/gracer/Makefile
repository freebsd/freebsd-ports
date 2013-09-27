# Created by: nox@jelal.kn-bremen.de
# $FreeBSD$

PORTNAME=	gracer
PORTVERSION=	0.1.5
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	nox@FreeBSD.org
COMMENT=	3D motor sport simulator

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	gif:${PORTSDIR}/graphics/giflib \
		png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

USE_GL=		glut
USES=		gmake perl5 tcl:84
USE_PERL5=	build
USE_AUTOTOOLS=	autoconf213
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include \
		-I${TCL_INCLUDEDIR}
NO_STAGE=	yes
# for plib (sound):
CONFIGURE_ARGS+=	--with-plib=${LOCALBASE}/plib

MAN6=		gracer.6

.include <bsd.port.pre.mk>

pre-patch:
	@${REINPLACE_CMD} -i '' -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/common/gr_memory.h

.include <bsd.port.post.mk>
