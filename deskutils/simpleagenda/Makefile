PORTNAME=	simpleagenda
PORTVERSION=	0.43
PORTREVISION=	13
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://coyote.octets.fr/pub/gnustep/
DISTNAME=	SimpleAgenda-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple calendar and agenda application
WWW=		http://wiki.gnustep.org/index.php/SimpleAgenda.app

LICENSE=	GPLv2

BROKEN=		Fails to build with unknown type name 'APPKIT_EXPORT_CLASS'

LIB_DEPENDS+=	libical.so:devel/libical \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		gnustep localbase
USE_GNUSTEP=	back build

GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|SimpleAgenda|SimpleAgenda.m|' ${WRKSRC}/configure

.include <bsd.port.mk>
