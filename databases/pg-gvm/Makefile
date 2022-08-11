PORTNAME=	pg-gvm
DISTVERSION=	22.4.0
DISTVERSIONPREFIX=v
CATEGORIES=	databases devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Greenbone Library for helper functions in PostgreSQL

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgvm_base.so:security/gvm-libs \
		libical.so:devel/libical

USES=		cmake gnome pkgconfig pgsql
USE_GNOME=	glib20

USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	pg-gvm

post-patch:
	@${REINPLACE_CMD} -e 's|find -type f|find * -type f|g' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
