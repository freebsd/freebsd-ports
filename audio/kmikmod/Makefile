# New ports collection makefile for:   kmikmod
# Date created:        1 March 1999
# Whom:                Tom Hukins <tom@eborcom.com>
#
# $FreeBSD$
#

PORTNAME=	kmikmod
PORTVERSION=	2.04
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	tom

MAINTAINER=	tom@FreeBSD.org

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		kdeui.3:${PORTSDIR}/x11/kdelibs11

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/kmikmod
USE_QT_VER=	1
USE_GMAKE=	yes
WANT_ESOUND=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libmikmod/configure

.include <bsd.port.pre.mk>

.if defined(HAVE_ESOUND)
USE_ESOUND=	yes
.endif

pre-configure:
	cd ${WRKSRC}/libmikmod; ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

.include <bsd.port.post.mk>
