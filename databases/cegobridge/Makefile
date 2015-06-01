# $FreeBSD$

PORTNAME=	cegobridge
PORTVERSION=	1.0.1
CATEGORIES=	databases
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Imports non-cego database dump files into cego

LIB_DEPENDS=	liblfcbase.so:${PORTSDIR}/devel/lfcbase \
		liblfcxml.so:${PORTSDIR}/devel/lfcxml \
		libcego.so:${PORTSDIR}/databases/cego

LICENSE=	GPLv3
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
PLIST_FILES=	bin/cegobridge

.include <bsd.port.mk>
