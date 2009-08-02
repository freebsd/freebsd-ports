# New ports collection makefile for:	giram
# Date created:				17 June 1999
# Whom:					Brandon Fosdick <bfoz@glue.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	giram
PORTVERSION=	0.3.5
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	http://www.giram.org/downloads/ \
		http://freebsd.nsu.ru/distfiles/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A POV-Ray oriented modeller

LIB_DEPENDS=	3ds-1.3:${PORTSDIR}/graphics/lib3ds

USE_GETTEXT=	yes
USE_PERL5_BUILD=yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		INTLTOOL_PERL="${PERL}"
CONFIGURE_ARGS=	--datadir="${PREFIX}/lib" \
		--with-tutorial-path="${DOCSDIR}" \
		--with-lib3ds-prefix="${LOCALBASE}"

OPTIONS=	POVRAY31	"Build against POV-Ray 3.1"	off

.include <bsd.port.pre.mk>

.if defined(WITH_POVRAY31)
BUILD_DEPENDS+=	povray:${PORTSDIR}/graphics/povray31
RUN_DEPENDS+=	povray:${PORTSDIR}/graphics/povray31
.else
BUILD_DEPENDS+=	povray:${PORTSDIR}/graphics/povray
RUN_DEPENDS+=	povray:${PORTSDIR}/graphics/povray
.endif

MAN1=		giram.1

post-patch:
	@${REINPLACE_CMD} -e '36s,static ,,' ${WRKSRC}/src/tools/tool_disc.c
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.pov ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
