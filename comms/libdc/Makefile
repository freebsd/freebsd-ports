PORTNAME=	libdc
DISTVERSIONPREFIX=v
DISTVERSION=	5.0.10
PORTREVISION=	1
CATEGORIES=	comms

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Subsurface version of libdivecomputer
WWW=		http://www.libdivecomputer.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	subsurface
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${PREFIX}/share/doc/libdivecomputer

.include <bsd.port.mk>
