# New ports collection makefile for:	streamtuner
# Date created:			02 Apr 2002
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		streamtuner
PORTVERSION=		0.11.0
CATEGORIES=		audio www
MASTER_SITES=		http://streamtuner.sourceforge.net/streamtuner/

MAINTAINER=		jylefort@brutele.be
COMMENT=		A GTK+ stream directory browser

LIB_DEPENDS=		curl:${PORTSDIR}/ftp/curl

USE_X_PREFIX=		yes
USE_GNOME=		gtk20 gnomehack
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"

MAN1=			streamtuner.1 streamtuner-theme-convert.1

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|[(]datadir[)]/pixmaps|(prefix)/share/gnome/pixmaps|g ; \
		 s|[(]datadir[)]/applications|(prefix)/share/gnome/applications|g'

.include <bsd.port.mk>
