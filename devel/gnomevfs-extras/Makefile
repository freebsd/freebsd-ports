# New ports collection makefile for:	gnomevfs-extras
# Date created:				20 January 2003
# Whom:					Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	gnomevfs-extras
PORTVERSION=	0.99.9
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-vfs-extras/0.99
DISTNAME=	gnome-vfs-extras-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	einekoai@chello.nl

LIB_DEPENDS=	gnomevfs-2.0:${PORTSDIR}/devel/gnomevfs2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--without-rio500
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

.include <bsd.port.mk>
