# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	ocrfeeder
PORTVERSION=	0.7.7
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=sources/ocrfeeder/${PORTVERSION:R}

MAINTAINER=	buganini@gmail.com
COMMENT=	Document layout analysis and optical character recognition

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enchant>=0:${PORTSDIR}/textproc/py-enchant \
		${PYTHON_PKGNAMEPREFIX}imaging>=0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}sane>=0:${PORTSDIR}/graphics/py-sane \
		${PYTHON_PKGNAMEPREFIX}reportlab2>=0:${PORTSDIR}/print/py-reportlab2 \
		${PYTHON_PKGNAMEPREFIX}goocanvas>=0:${PORTSDIR}/graphics/py-goocanvas
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		unpaper:${PORTSDIR}/graphics/unpaper

MAN1=		ocrfeeder-cli.1 ocrfeeder.1

USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_GNOME=	pygtk2 pygnomeextras
USES=		gettext gmake pkgconfig
USE_GHOSTSCRIPT=yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
