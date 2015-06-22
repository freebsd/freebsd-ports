# Created by: nox@jelal.kn-bremen.de
# $FreeBSD$

PORTNAME=	gracer
PORTVERSION=	0.1.5
PORTREVISION=	19
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	nox@FreeBSD.org
COMMENT=	3D motor sport simulator

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	libgif.so:${PORTSDIR}/graphics/giflib \
		libpng.so:${PORTSDIR}/graphics/png

USE_GL=		glut
USES=		gmake jpeg perl5 tcl:84
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-plib=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include \
		-I${TCL_INCLUDEDIR}
LIBS+=		-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/common/gr_memory.h
	@${REINPLACE_CMD} \
		-e 's|lib/tclConfig.sh|lib/tcl${TCL_VER}/tclConfig.sh|' \
		-e '/SOUND_LIBS=/s/"$$/ -lplibul"/' \
		${WRKSRC}/configure

.include <bsd.port.mk>
