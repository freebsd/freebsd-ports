# Created by: nox@jelal.kn-bremen.de

PORTNAME=	gracer
PORTVERSION=	0.1.5
PORTREVISION=	23
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D motor sport simulator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_13=	ld: error: duplicate symbol: GrBreak
BROKEN_FreeBSD_14=	ld: error: duplicate symbol: GrBreak

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib
LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png

USES=		gl gmake jpeg localbase perl5 tcl
USE_GL=		glut
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-plib=${LOCALBASE}
CPPFLAGS+=	-I${TCL_INCLUDEDIR}

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|<malloc.h>|<stdlib.h>|' \
		${WRKSRC}/common/gr_memory.h
	@${REINPLACE_CMD} \
		-e 's|lib/tclConfig.sh|lib/tcl${TCL_VER}/tclConfig.sh|' \
		-e '/SOUND_LIBS=/s/"$$/ -lplibul"/' \
		${WRKSRC}/configure

.include <bsd.port.mk>
