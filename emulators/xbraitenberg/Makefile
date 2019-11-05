# Created by: krion
# $FreeBSD$

PORTNAME=	xbraitenberg
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://www.lcdf.org/~eddietwo/xbraitenberg/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Braitenberg vehicle simulator with pseudo-physics

USES=		xorg
USE_CXXSTD=	c++98
USE_XORG=	x11 ice sm xext
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_fpermissive=no

PLIST_FILES=	bin/xbraitenberg

post-patch:
	@${REINPLACE_CMD} -e \
		'/operator bool() const/d' ${WRKSRC}/operator.hh

.include <bsd.port.mk>
