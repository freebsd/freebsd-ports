# New ports collection makefile for:	plotutils
# Date created:		19 June 1998
# Whom:			Chuck Robey (chuckr)
#
# $FreeBSD$
#

PORTNAME=	plotutils
PORTVERSION=	2.4.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	chuckr@FreeBSD.org

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_MOTIF=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -fpermissive" \
		MOTIFLIB="${MOTIFLIB}" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-libplotter --enable-libxmi --with-motif
INSTALLS_SHLIB=	yes

MAN1=		ode.1 plot.1 plotfont.1 spline.1 tek2plot.1

pre-patch:
	@${PERL} -pi -e 's|-lXm |\$$\{MOTIFLIB\} |g' ${WRKSRC}/configure

.include <bsd.port.mk>
