PORTNAME=	configkit
PORTVERSION=	0.4.20080902
CATEGORIES=	devel
MASTER_SITES=	http://phk.freebsd.dk/phkrel/
DISTNAME=	ConfigKit.${PORTVERSION:C/0.4.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Somewhat prototypical facility for generating CLI interfaces
WWW=		http://phk.freebsd.dk/phkrel/

DEPRECATED=	Depends on deprecated port devel/libphk
EXPIRATION_DATE=2024-04-30

BUILD_DEPENDS=	${LOCALBASE}/lib/libphk.a:devel/libphk

USES=		uidfix

MAKE_ARGS=	BINDIR=${PREFIX}/bin LIBDIR=${PREFIX}/lib INCLUDEDIR=${PREFIX}/include

WRKSRC=		${WRKDIR}/ConfigKit

.include <bsd.port.options.mk>

.if defined(NO_PROFILE) || ( ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079 )
PLIST_SUB+=     PROFILE="@comment "
.else
PLIST_SUB+=     PROFILE=""
.endif

.include <bsd.port.mk>
