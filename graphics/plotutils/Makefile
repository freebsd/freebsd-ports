# New ports collection makefile for:	plotutils
# Date created:		19 June 1998
# Whom:			Chuck Robey (chuckr)
#
# $FreeBSD$
#

PORTNAME=	plotutils
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A plotting library and toolkit

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		MOTIFLIB="${MOTIFLIB}" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-libplotter --enable-libxmi --with-motif
INSTALLS_SHLIB=	yes

MAN1=		ode.1 plot.1 plotfont.1 spline.1 tek2plot.1

INFO=	libxmi plotutils

pre-patch:
	@${REINPLACE_CMD} -e 's|-lXm |\$$\{MOTIFLIB\} |g ; \
		s|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
