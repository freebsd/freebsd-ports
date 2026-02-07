PORTNAME=	gracer
PORTVERSION=	0.1.5
PORTREVISION=	26
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D motor sport simulator
WWW=		https://gracer.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:x11-toolkits/plib
LIB_DEPENDS=	libgif.so:graphics/giflib \
		libpng.so:graphics/png

USES=		gl gmake jpeg localbase perl5 tcl xorg
USE_GL=		gl glu glut
USE_PERL5=	build
USE_XORG=	ice sm x11 xext xi xmu xt
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
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
