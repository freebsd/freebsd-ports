# New ports collection makefile for:	giram
# Date created:        17 June 1999
# Whom:                Brandon Fosdick <bfoz@glue.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	giram
PORTVERSION=	0.3.5
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.giram.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A POV-Ray oriented modeller

LIB_DEPENDS=	3ds.1:${PORTSDIR}/graphics/lib3ds

BROKEN=		"Does not compile"

USE_X_PREFIX=	yes
USE_PERL5_BUILD=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
LIBTOOLFLAGS=	# none
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		INTLTOOL_PERL="${PERL}"
CONFIGURE_ARGS=	--datadir="${PREFIX}/lib" \
		--with-tutorial-path="${DOCSDIR}" \
		--with-lib3ds-prefix="${LOCALBASE}"
MAN1=		giram.1

.if defined(WITH_POVRAY31)
BUILD_DEPENDS+=	povray:${PORTSDIR}/graphics/povray31
RUN_DEPENDS+=	povray:${PORTSDIR}/graphics/povray31
.else
BUILD_DEPENDS+=	povray:${PORTSDIR}/graphics/povray
RUN_DEPENDS+=	povray:${PORTSDIR}/graphics/povray
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.pov ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
