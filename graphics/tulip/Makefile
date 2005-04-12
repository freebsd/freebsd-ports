# ex:ts=8
# Ports collection makefile for:	tulip
# Date created:			Feb 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tulip
PORTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://dept-info.labri.fr/~auber/projects/tulip/x345/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A system dedicated to the visualization of huge graphs

LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/libglut

USE_BZIP2=	yes
USE_QT_VER=	3
QT_NONSTANDARD=	yes
USE_REINPLACE=	yes
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	MOC="${MOC}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-qt-includes=${QT_PREFIX}/include \
		--with-qt-libraries=${QT_PREFIX}/lib \
		--with-extra-libs=${LOCALBASE}/lib
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${LOCALBASE}/include -I${PREFIX}/include \
		-I${QT_PREFIX}/include -DHAVE_DECL_GETOPT ${PTHREAD_CFLAGS}
LDFLAGS=	-Wl,-export-dynamic -L${LOCALBASE}/lib -L${X11BASE}/lib \
		-ljpeg -L${QT_PREFIX}/lib -lcompat ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-extract:
	@${FIND} ${WRKSRC} -name "moc_*" -delete

post-patch:
	@${REINPLACE_CMD} -e 's| -O2 -pipe||g' ${WRKSRC}/configure
	@${GREP} -lR "malloc\.h" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-ldl||g ; \
		 s|-lpthread||g ; \
		 s|-release @TULIP_VERSION@|| ; \
		 s|LDFLAGS = -module|LDFLAGS = @LDFLAGS@ -module|g'

.include <bsd.port.post.mk>
