# New ports collection makefile for:	knoda
# Date created:				26.7.2002
# Whom:					arved
#
# $FreeBSD$

PORTNAME=		knoda
PORTVERSION=		0.7.3
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		sem@FreeBSD.org
COMMENT=		Database frontend for KDE

BUILD_DEPENDS=		${LOCALBASE}/include/argp.h:${PORTSDIR}/devel/argp-standalone
LIB_DEPENDS=		hk_classes.7:${PORTSDIR}/databases/hk_classes

USE_BZIP2=		yes
USE_KDELIBS_VER=	3
USE_PYTHON=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
INSTALLS_SHLIB=		yes
USE_INC_LIBTOOL_VER=	13
USE_REINPLACE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		--with-hk_classes-dir=${LOCALBASE}/lib/hk_classes \
		--with-hk_classes-incdir=${LOCALBASE}/include/hk_classes

post-patch:
	${REINPLACE_CMD} -e 's,-pedantic ,,' ${WRKSRC}/configure

.include <bsd.port.mk>
