# New ports collection makefile for:   kmikmod
# Version required:    2.04
# Date created:        1 March 1999
# Whom:                Tom Hukins <tom@eborcom.com>
#
# $FreeBSD$
#

DISTNAME=	kmikmod-2.04
CATEGORIES=	audio kde
MASTER_SITES=	http://myy.helia.fi/~anttiner/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tom@eborcom.com

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	kdecore.2:${PORTSDIR}/x11/kdelibs11 \
		kdeui.2:${PORTSDIR}/x11/kdelibs11

WRKSRC=		${WRKDIR}/kmikmod
USE_QT=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

pre-configure:
	cd ${WRKSRC}/libmikmod; ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

.include <bsd.port.mk>
