# New ports collection makefile for:	gedit
# Date created:				4 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gedit
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gedit

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	msgfmt-old:${PORTSDIR}/devel/gettext-old

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		MSGFMT="${LOCALBASE}/bin/msgfmt-old" \
		XGETTEXT="${LOCALBASE}/bin/xgettext-old"

MAN1=		gedit.1

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${REINPLACE_CMD} -e \
		's|[(]datadir[)]/gnome/|(datadir)/|g ; \
		 s|[(]datadir[)]/locale|(prefix)/share/locale|g'

.include <bsd.port.mk>
