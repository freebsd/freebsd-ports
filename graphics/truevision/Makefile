# ex:ts=8
# Ports collection makefile for:	truevision
# Date created:			Mar 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	truevision
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GNOME 3D modeler

LIB_DEPENDS=	gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GL=		yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui
USE_GMAKE=	yes
USE_AUTOMAKE_VER=	14
AUTOMAKE_ARGS=	--add-missing --include-deps
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}

post-extract:
	@${FIND} ${WRKSRC} -type l -delete
	@${FIND} ${WRKSRC} -name "*.o" -delete
	@${FIND} ${WRKSRC} -name "config.cache" -delete

post-install:
	@${MKDIR} ${PREFIX}/share/gnome/Truevision
	${TAR} -C ${WRKSRC} --exclude "CVS" -cf - materials | \
		${TAR} -C ${PREFIX}/share/gnome/Truevision --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/gnome/Truevision

.include <bsd.port.mk>
