# Created by: Brandon Fosdick <bfoz@glue.umd.edu>
# $FreeBSD$

PORTNAME=	giram
PORTVERSION=	0.3.5
PORTREVISION=	17
CATEGORIES=	graphics
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POV-Ray oriented modeller

LIB_DEPENDS=	lib3ds-1.so:${PORTSDIR}/graphics/lib3ds
BUILD_DEPENDS=	povray:${PORTSDIR}/graphics/povray-meta
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gettext perl5 pkgconfig gmake
USE_PERL5=	build
USE_GNOME=	gtk20
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	INTLTOOL_PERL="${PERL}"
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--datadir="${PREFIX}/lib" \
		--with-tutorial-path="${DOCSDIR}" \
		--with-lib3ds-prefix="${LOCALBASE}"
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '36s,static ,,' ${WRKSRC}/src/tools/tool_disc.c
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.pov ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
