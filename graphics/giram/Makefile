# Created by: Brandon Fosdick <bfoz@glue.umd.edu>
# $FreeBSD$

PORTNAME=	giram
PORTVERSION=	0.3.5
PORTREVISION=	20
CATEGORIES=	graphics
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POV-Ray oriented modeller

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	lib3ds.so:graphics/lib3ds
BUILD_DEPENDS=	povray:graphics/povray-meta
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gettext gmake libtool perl5 pkgconfig
USE_PERL5=	build
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INTLTOOL_PERL="${PERL}"
CONFIGURE_ARGS=	--datadir="${PREFIX}/lib" \
		--disable-static \
		--with-tutorial-path="${DOCSDIR}" \
		--with-lib3ds-prefix="${LOCALBASE}"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} '/^giram_LDADD =/s/$$/ -lgmodule-2.0/' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} '/DiscWithHoleFlag/d' ${WRKSRC}/src/tools/tool_disc.h

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/giram/0.3/modules/*.so
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.pov ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
