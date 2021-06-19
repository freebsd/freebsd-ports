# Created by: Igor Pokrovsky <tiamat@telegraph.spb.ru>

PORTNAME=	gltt
PORTVERSION=	2.5.2
PORTREVISION=	15
CATEGORIES=	graphics
MASTER_SITES=	http://gltt.sourceforge.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TrueType fonts rendering using OpenGL

LIB_DEPENDS=	libttf.so:print/freetype

USES=		gl gmake libtool
USE_GL=		gl glut
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-ttf-includes=${LOCALBASE}/include/freetype1 \
		--with-ttf-libraries=${LOCALBASE}/lib \
		--with-gl-includes=${LOCALBASE}/include \
		--with-gl-libraries=${LOCALBASE}/lib \
		--with-glut-includes=${LOCALBASE}/include \
		--with-glut-libraries=${LOCALBASE}/lib
USE_LDCONFIG=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgltt.so

.include <bsd.port.mk>
