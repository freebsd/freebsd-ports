PORTNAME=	aardvark-dns
DISTVERSIONPREFIX=	v
DISTVERSION=	1.17.0
CATEGORIES=	dns

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Authoritative dns server for A/AAAA container records
WWW=		https://github.com/containers/aardvark-dns

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	containers

PLIST_FILES=	bin/aardvark-dns

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1500050
LIB_DEPENDS=	libinotify.so:devel/libinotify
USES+=		localbase:ldflags
LDFLAGS+=	-linotify
.endif

.include <bsd.port.mk>
