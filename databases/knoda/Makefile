# New ports collection makefile for:	knoda
# Date created:				26.7.2002
# Whom:					arved
#
# $FreeBSD$

PORTNAME=		knoda
PORTVERSION=		0.6.1
PORTREVISION=		2
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	knoda

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Database frontend for KDE

LIB_DEPENDS=		hk_classes.5:${PORTSDIR}/databases/hk_classes

USE_KDELIBS_VER=	3
USE_PYTHON=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes
USE_LIBTOOL=		yes
USE_REINPLACE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--with-hk_classes-dir=${LOCALBASE}/lib/hk_classes \
		--with-hk_classes-incdir=${LOCALBASE}/include/hk_classes

post-patch:
	${REINPLACE_CMD} -e 's,-pedantic ,,' ${WRKSRC}/configure

.include <bsd.port.mk>
