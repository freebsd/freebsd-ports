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

USES=		gmake pathfix pkgconfig
USE_GNOME=	pygnome2
USE_PYTHON=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	PRINT
OPTIONS_DEFAULT=PRINT
PRINT_DESC=	GNOME print support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPRINT}
USE_GNOME+=	libgnomeprintui
CONFIGURE_ARGS+=--enable-gnome-print
.else
CONFIGURE_ARGS+=--disable-gnome-print
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|unit_tests doc|unit_tests|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
