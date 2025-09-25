PORTNAME=	ancient
PORTVERSION=	2.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	archivers

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Decompression routines for ancient formats
WWW=		https://github.com/temisu/ancient

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive

USES=		autoreconf gmake libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	temisu
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
