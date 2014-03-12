# Created by: ijliao
# $FreeBSD$

PORTNAME=	diacanvas2
PORTVERSION=	0.15.4
PORTREVISION=	4
CATEGORIES=	graphics gnome
MASTER_SITES=	SF/diacanvas/DiaCanvas2/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General drawing canvas from dia dialog editor

LICENSE=	GPLv2

USES=		gmake pathfix pkgconfig
USE_GNOME=	pygnome2
USE_PYTHON=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	NLS PRINT
OPTIONS_DEFAULT=PRINT
PRINT_DESC=	GNOME print support
OPTIONS_SUB=	yes

PRINT_CONFIGURE_ENABLE=	gnome-print

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPRINT}
USE_GNOME+=	libgnomeprintui
.endif

post-patch:
	@${REINPLACE_CMD} -e '/SUBDIRS/s|doc||' ${WRKSRC}/Makefile.in

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e 's|po diacanvas po |diacanvas |' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.0
.for l in _canvasmodule shapemodule viewmodule geometrymodule
	${STRIP_CMD} ${STAGEDIR}${PYTHON}${PYTHON_SITELIBDIR}/diacanvas/${l}.so
.endfor

.include <bsd.port.mk>
