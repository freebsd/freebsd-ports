PORTNAME=	hyprwire
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Fast and consistent wire protocol for IPC
WWW=		https://github.com/hyprwm/hyprwire

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhyprutils.so:devel/hyprutils \
		libffi.so:devel/libffi \
		libpugixml.so:textproc/pugixml

USES=		cmake:testing compiler:c++11-lib pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

LDFLAGS+=	-pthread

PLIST_SUB=	SOVERSION_FULL=${DISTVERSION} \
		SOVERSION_MAJOR=3
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
