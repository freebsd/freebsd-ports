# New ports collection makefile for:	libgeda
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	libgeda
PORTVERSION=	20070216
PORTREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PORTVERSION}/ \
		http://geda.seul.org/devel/${PORTVERSION}/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	The gEDA's tools base utility library

LIB_DEPENDS=	gdgeda.6:${PORTSDIR}/graphics/libgdgeda \
		guile.19:${PORTSDIR}/lang/guile

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 gnomehack
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-gdgeda
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s,^(DATADIR[[:space:]]*=[[:space:]]*)gEDA,\1geda," \
		${WRKSRC}/configure

.include <bsd.port.mk>
