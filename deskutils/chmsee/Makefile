# New ports collection makefile for:	chmsee
# Date created:                		10 June 2006
# Whom:                    		Liu.Yinghong <liu_yinghong@yahoo.com.cn>
#
# $FreeBSD$
#

PORTNAME=	chmsee
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://chmsee.gro.clinux.org/

MAINTAINER=	liu_yinghong@yahoo.com.cn
COMMENT=	A viewer for Microsoft Help "CHM" files

LIB_DEPENDS=	chm.0:${PORTSDIR}/misc/chmlib

USE_GETTEXT=	yes
USE_GNOME=	gtk20 libglade2 gnomeprefix gnomehack libgnome gtkhtml3
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|libgtkhtml-3.8|libgtkhtml-3.14|g' \
	    	${WRKSRC}/configure

.include <bsd.port.mk>
