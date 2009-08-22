# New ports collection makefile for:	knoda
# Date created:				26.7.2002
# Whom:					arved
#
# $FreeBSD$

PORTNAME=		knoda
PORTVERSION=		0.8.1
PORTREVISION=	3
CATEGORIES=		databases
MASTER_SITES=		SF

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Database frontend for KDE

BUILD_DEPENDS=		${LOCALBASE}/include/argp.h:${PORTSDIR}/devel/argp-standalone
LIB_DEPENDS=		hk_classes.13:${PORTSDIR}/databases/hk_classes

USE_BZIP2=		yes
USE_KDELIBS_VER=	3
USE_PYTHON=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool:22
USE_LDCONFIG=		yes
CONFIGURE_ARGS+=	--with-hk_classes-dir=${LOCALBASE}/lib/hk_classes \
		--with-hk_classes-incdir=${LOCALBASE}/include/hk_classes

post-patch:
	${REINPLACE_CMD} -e 's,-pedantic ,,' ${WRKSRC}/configure

.include <bsd.port.mk>
