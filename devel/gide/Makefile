# New ports collection makefile for:	gIDE
# Date created:				29 Jul 1998
# Whom:					rom
#
# $FreeBSD$
#

PORTNAME= 	gide
PORTVERSION= 	0.1.7
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME} \
		http://gide.pn.org/
MASTER_SITE_SUBDIR=	unstable/sources/gIDE
DISTNAME= 	gIDE-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnomeui.3:${PORTSDIR}/x11/gnomelibs \
		guile.6:${PORTSDIR}/lang/guile

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex"
CONFIGURE_ARGS=	--with-gnome=${PREFIX}

MAN1=		gide.1 gdbio.1

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/src/*.c
	@${PERL} -pi -e "s|%%X11BASE%%|${X11BASE}|g" ${WRKSRC}/src/*.c

.include <bsd.port.mk>
