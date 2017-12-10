# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	ganyremote
PORTVERSION=	6.3.3
PORTREVISION=	1
CATEGORIES=	deskutils comms gnome
MASTER_SITES=	SF/anyremote/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME frontend for anyRemote

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	anyremote:comms/anyremote

USES=		gettext python:2.7 shebangfix
SHEBANG_FILES=	ganyremote
USE_GNOME=	pygtk2
GNU_CONFIGURE=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}| ; \
		 /usepybluez = /s|True|False| ; \
		 /initVerify()$$/d' ${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} -e \
		'/DESTDIR/s|cp -r|cp -R| ; \
		 /DESTDIR/s|COPYING||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
