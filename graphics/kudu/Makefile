# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	kudu
PORTVERSION=	0.1.2
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D skeletal animation tool, powered by GTK+ and OpenGL

LICENSE=	GPLv2

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext

USES=		tar:bzip2 pkgconfig python
GNU_CONFIGURE=	yes
USE_GL=		gl

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lcompat -lm

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

DESKTOP_ENTRIES="Kudu" \
		"Edit 3D models" \
		"${DATADIR}/images/logo.png" \
		"kudu" \
		"Graphics;3DGraphics;GTK;" \
		true

post-patch:
	@${REINPLACE_CMD} -e 's|COPYING||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
