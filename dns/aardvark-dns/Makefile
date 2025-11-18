PORTNAME=	aardvark-dns
PORTVERSION=	1.17.0
DISTVERSIONPREFIX=	v
CATEGORIES=	dns

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Authoritative dns server
WWW=		https://github.com/containers/aardvark-dns

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libinotify.so:devel/libinotify

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	containers

.if !exists(/usr/include/sys/inotify.h)
LDFLAGS+=	-L${LOCALBASE}/lib -linotify
.endif

.include "${.CURDIR}/Makefile.crates"

PLIST_FILES=	bin/aardvark-dns

.include <bsd.port.mk>
