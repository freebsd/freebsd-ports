# Created by: Per Wigren
# $FreeBSD$

PORTNAME=	unadf
PORTVERSION=	0.7.12
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://lclevy.free.fr/adflib/
DISTNAME=	adflib-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extracts files from .adf-files used by Amiga emulators

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool pathfix tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/adflib
INSTALL_TARGET=	install-strip

DOCSDIR=	${PREFIX}/share/doc/adflib

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
