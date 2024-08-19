PORTNAME=	fyi
DISTVERSION=	1.0.3
CATEGORIES=	deskutils
MASTER_SITES=	https://codeberg.org/dnkl/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Command line utility to send desktop notifications
WWW=		https://codeberg.org/dnkl/fyi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdbus-1.so:devel/dbus

USES=	meson
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	scdoc:textproc/scdoc
DOCS_MESON_ENABLED=	docs

.include <bsd.port.mk>
