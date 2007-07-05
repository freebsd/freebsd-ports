# New ports collection makefile for:	chmsee
# Date created:                		10 June 2006
# Whom:                    		Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	chmsee
PORTVERSION=	0.9.6
PORTREVISION=	4
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://chmsee.gro.clinux.org/

MAINTAINER=	relaxbsd@gmail.com
COMMENT=	A viewer for Microsoft Help "CHM" files

LIB_DEPENDS=	chm.0:${PORTSDIR}/misc/chmlib \
		gtkhtml-3.14:${PORTSDIR}/www/gtkhtml3

USE_GETTEXT=	yes
USE_GNOME=	gtk20 libglade2 gnomeprefix gnomehack libgnome
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} 's|libgtkhtml-3.8|libgtkhtml-3.14|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
