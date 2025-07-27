PORTNAME=	aml
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Another Main Loop
WWW=		https://github.com/any1/aml

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	any1

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
