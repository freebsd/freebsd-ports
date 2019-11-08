# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	ganyremote
PORTVERSION=	7.0
CATEGORIES=	deskutils comms gnome
MASTER_SITES=	SF/anyremote/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME frontend for anyRemote

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	anyremote:comms/anyremote

USES=		gnome python:2.7 shebangfix
SHEBANG_FILES=	ganyremote
USE_GNOME=	pygobject3 gtk30
GNU_CONFIGURE=	yes
NO_ARCH=	yes

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=			DOCS IMAGEMAGICK NLS
OPTIONS_SUB=			yes
IMAGEMAGICK_DESC=		ImageMagick Support
IMAGEMAGICK_RUN_DEPENDS=	ImageMagick7>0:graphics/ImageMagick7
IMAGEMAGICK_USES+=		gettext
NLS_CONFIGURE_ENABLE=		nls

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}| ; \
		 /usepybluez = /s|True|False| ; \
		 /initVerify()$$/d' ${WRKSRC}/${PORTNAME}
	@${REINPLACE_CMD} -e \
		'/DESTDIR/s|cp -r|cp -R| ; \
		 /DESTDIR/s|COPYING||' ${WRKSRC}/Makefile.in
#do-install-DOCS-off:
#	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
