# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	ganyremote
PORTVERSION=	6.3.1
CATEGORIES=	deskutils comms gnome
MASTER_SITES=	SF/anyremote/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME frontend for anyRemote

LICENSE=	GPLv2 # (or later)

RUN_DEPENDS=	anyremote:${PORTSDIR}/comms/anyremote

OPTIONS_DEFINE=	DOCS

USES=		gettext
USE_GNOME=	pygtk2
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}| ; \
		 /usepybluez = /s|True|False| ; \
		 /initVerify()$$/d' ${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} -e \
		'/DESTDIR/s|cp -r|cp -R| ; \
		 /DESTDIR/s|COPYING||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
