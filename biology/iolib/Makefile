PORTNAME=	io_lib
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1-14-10
PORTREVISION=	1
CATEGORIES=	biology

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose trace file (and Experiment File) reading interface
WWW=		https://staden.sourceforge.net/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		autoreconf gmake libtool

USE_GITHUB=	yes
GH_ACCOUNT=	jkbonfield

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
LDFLAGS+=	-lpthread

CONFLICTS_INSTALL=	filters scramble # bin/scramble

.include <bsd.port.mk>
