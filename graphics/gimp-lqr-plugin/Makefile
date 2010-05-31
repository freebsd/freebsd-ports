# New ports collection makefile for:	gimp-lqr
# Date created:		27 Sep 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	gimp-lqr-plugin
PORTVERSION=	0.6.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://liquidrescale.wdfiles.com/local--files/en:download-page/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Liquid rescale GIMP plug-in

LIB_DEPENDS=	gimp-2.0:${PORTSDIR}/graphics/gimp-app \
		lqr-1.3:${PORTSDIR}/graphics/liblqr-1

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20
MAKE_JOBS_SAFE=	yes

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins
PLIST_SUB=	PLUGIN_DIR=${PLUGIN_DIR}

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|^bindir = .*|bindir = ${PREFIX}/${PLUGIN_DIR}|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
