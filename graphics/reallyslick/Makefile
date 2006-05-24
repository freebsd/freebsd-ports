# New ports collection makefile for:	reallyslick
# Date created:				24 Nov 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	reallyslick
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rss-glx
DISTNAME=	rss-glx_${PORTVERSION}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	OpenGL screensaver collection

LIB_DEPENDS=	Wand.10:${PORTSDIR}/graphics/ImageMagick

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15:env

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	biof.1 busyspheres.1 colorfire.1 cyclone.1 euphoria.1 fieldlines.1 flocks.1 \
	flux.1 helios.1 hufo_smoke.1 hufo_tunnel.1 lattice.1 matrixview.1 \
	plasma.1 skyrocket.1 solarwinds.1 spirographx.1 sundancer2.1

post-patch:
.for file in config.guess config.sub ltmain.sh
	${RM} ${WRKSRC}/${file}
	${LN} -s ${LOCALBASE}/share/libtool/${file} ${WRKSRC}
.endfor
.for file in oglc_src/Makefile.in other_src/Makefile.in \
		reallyslick/c_src/Makefile.in reallyslick/cpp_src/Makefile.in
	@${REINPLACE_CMD} -E -e 's|(@LIBS@)|\1 -lXext|' ${WRKSRC}/${file}
.endfor
# fix lib detection
	@${REINPLACE_CMD} -E -e 's@^(LIBS.*-l(GL|MesaGL|GLU))@\1 -lXext@' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
