# New ports collection makefile for:	imlib
# Version required:	1.9.4
# Date created:		10 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.46 1999/03/27 10:35:57 vanilla Exp $
#

DISTNAME=	imlib-1.9.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/imlib

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=    png.3:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff34 \
		gif.3:${PORTSDIR}/graphics/giflib \
		gtk12.1:${PORTSDIR}/x11-toolkits/gtk12

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/imlib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
			-I${LOCALBASE}/include/giflib" \
		GTK_CONFIG="${X11BASE}/bin/gtk12-config" \
		LIBS="-L${LOCALBASE}/lib"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	@${ECHO} '************************************************************'
	@${ECHO} '*                                                          *'
	@${ECHO} '*     If you want to use autoconf with imlib,              *'
	@${ECHO} '*     Please copy imlib.m4 to /usr/local/share/aclocal     *'
	@${ECHO} '*     by yourself, thanks.                                 *'
	@${ECHO} '*                                                          *'
	@${ECHO} '************************************************************'

.include <bsd.port.mk>
