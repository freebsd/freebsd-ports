# New ports collection makefile for:	gperiodic
# Version required:			1.2.2
# Date created:				16 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	gperiodic-1.2.2
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.seul.org/pub/gperiodic/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/gperiodic

MAN1=		gperiodic.1

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		GLIB_CONFIG="${LOCALBASE}/bin/glib12-config" \
		GTK_CONFIG="${X11BASE}/bin/gtk12-config"

post-install:
	@ ${INSTALL_MAN} ${WRKSRC}/man/gperiodic.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/gperiodic
.for file in AUTHORS COPYING Changes README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gperiodic
.endfor
.endif

.include <bsd.port.mk>
