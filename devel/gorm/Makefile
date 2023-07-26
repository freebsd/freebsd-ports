PORTNAME=	gorm
PORTVERSION=	1.2.23
PORTREVISION=	5
CATEGORIES=	devel gnustep

USE_GITHUB=	yes
GH_ACCOUNT=	gnustep
GH_PROJECT=	apps-gorm
GH_TAGNAME=	04554d2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical Object Relationship Modeller
WWW=		http://www.gnustep.org/experience/Gorm.html

LICENSE=	GPLv3

USES=		gnustep
USE_GNUSTEP=	back build
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

DEFAULT_LIBVERSION=	1.1.0

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CPPFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
