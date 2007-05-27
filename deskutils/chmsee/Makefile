# New ports collection makefile for:	chmsee
# Date created:                		10 June 2006
# Whom:                    		Liu.Yinghong <liu_yinghong@yahoo.com.cn>
#
# $FreeBSD$
#

PORTNAME=	chmsee
PORTVERSION=	0.9.6
PORTREVISION=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://chmsee.gro.clinux.org/

MAINTAINER=	liu_yinghong@yahoo.com.cn
COMMENT=	A viewer for Microsoft Help "CHM" files

LIB_DEPENDS=	chm.0:${PORTSDIR}/misc/chmlib \
    		gtkhtml-3.8.15:${PORTSDIR}/www/gtkhtml38

USE_GETTEXT=	yes
USE_GNOME=	gtk20 libglade2 gnomeprefix gnomehack libgnome
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
