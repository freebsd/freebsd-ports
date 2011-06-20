# New ports collection makefile for:	giram
# Date created:				17 June 1999
# Whom:					Brandon Fosdick <bfoz@glue.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	giram
PORTVERSION=	0.3.5
PORTREVISION=	16
CATEGORIES=	graphics
MASTER_SITES=	http://freebsd.nsu.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A POV-Ray oriented modeller

LIB_DEPENDS=	3ds-1.3:${PORTSDIR}/graphics/lib3ds
BUILD_DEPENDS=	povray:${PORTSDIR}/graphics/povray-meta
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GETTEXT=	yes
USE_PERL5_BUILD=yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		INTLTOOL_PERL="${PERL}"
CONFIGURE_ARGS=	--datadir="${PREFIX}/lib" \
		--with-tutorial-path="${DOCSDIR}" \
		--with-lib3ds-prefix="${LOCALBASE}"
CPPFLAGS=	-I${LOCALBASE}/include

MAN1=		giram.1

post-patch:
	@${REINPLACE_CMD} -e '36s,static ,,' ${WRKSRC}/src/tools/tool_disc.c
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.pov ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
