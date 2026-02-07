PORTNAME=	io_lib
DISTVERSION=	1-15-1
CATEGORIES=	biology
MASTER_SITES=	https://github.com/jkbonfield/${PORTNAME}/releases/download/${DISTNAME:S/./-/g}/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	General purpose trace file (and Experiment File) reading interface
WWW=		https://staden.sourceforge.net/ \
		https://github.com/jkbonfield/io_lib/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		autoreconf gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	filters scramble # bin/scramble

.include <bsd.port.mk>
