PORTNAME=	aardvark-dns
DISTVERSIONPREFIX=	v
DISTVERSION=	1.17.0
CATEGORIES=	dns

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Authoritative dns server
WWW=		https://github.com/containers/aardvark-dns

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	containers

.if !exists(/usr/include/sys/inotify.h)
LIB_DEPENDS=	libinotify.so:devel/libinotify
LDFLAGS+=	-L${LOCALBASE}/lib -linotify
.endif

.include "${.CURDIR}/Makefile.crates"

PLIST_FILES=	bin/aardvark-dns

.include <bsd.port.mk>
