# New ports collection makefile for:	superswitcher
# Date Created:				02 Jan 2006
# Whom:					Remington Lang <MrL0Lz@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	superswitcher
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF/browserbookapp/${PORTNAME}/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alt-Tab replacement

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common
RUN_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common

USE_GMAKE=	yes
USE_GNOME=	gtk20 libwnck pango
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-extract:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${RM} -f

post-patch:
	@${REINPLACE_CMD} -e 's/x11//g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>
