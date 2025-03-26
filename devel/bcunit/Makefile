PORTNAME=	bcunit
PORTVERSION=	5.4.2
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Fork of defunct project CUnit, with several fixes and patches applied
WWW=		https://gitlab.linphone.org/BC/public/bcunit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf cmake libtool pathfix pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
CAKE_ARGS=	-DENABLE_BCUNIT_DEPRECATED=ON
USE_LDCONFIG=	yes

.include <bsd.port.mk>
