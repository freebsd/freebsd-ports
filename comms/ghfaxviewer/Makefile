# Created by: Dominik Brettnacher <domi@saargate.de>
# $FreeBSD$

PORTNAME=	ghfaxviewer
PORTVERSION=	0.22.0
PORTREVISION=	13
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	halifax

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME compliant fax viewer capable of displaying TIFF G3 faxes

LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff

USE_GMAKE=	yes
USES=		pathfix
USE_GNOME=	gnomeprefix gconf gnomeprint
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=	halifax.1 ghfaxviewer.1

NO_STAGE=	yes
pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
