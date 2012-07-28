# ports collection makefile for:	kudu
# Date created:		28 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	kudu
PORTVERSION=	0.1.2
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D skeletal animation tool, powered by GTK+ and OpenGL

LIB_DEPENDS=	gtkglext-x11-1.0.0:${PORTSDIR}/x11-toolkits/gtkglext

USE_GL=		gl
USE_PYTHON=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS} -lcompat"

DESKTOP_ENTRIES="Kudu" \
		"Edit 3D models" \
		"${DATADIR}/images/logo.png" \
		"kudu" \
		"Application;Graphics;" \
		true

post-patch:
	@${REINPLACE_CMD} -e 's|COPYING||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
