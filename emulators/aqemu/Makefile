PORTNAME=	aqemu
DISTVERSION=	0.9.6.g20250311
CATEGORIES=	emulators

MAINTAINER=	kenrap@FreeBSD.org
COMMENT=	Qt-based QEMU frontend
WWW=		https://github.com/AQEMU/aqemu

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libvncclient.so:net/libvncserver

USES=		cmake compiler:c++17-lang qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	AQEMU
GH_TAGNAME=	76920e56a187fb7361a371b89ea3881a62f86596

USE_QT=		base declarative

CMAKE_ARGS=	-DINSTALL_MAN=ON \
		-DMAN_PAGE_COMPRESSOR=gzip

PORTDOCS=	AUTHORS.bz2 CHANGELOG.bz2 README.bz2 TODO.bz2

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
