PORTNAME=	dnst
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0-alpha2
PORTREVISION=	1
CATEGORIES=	dns net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	DNS administration toolbox including re-implementations of important ldns programs
WWW=		https://github.com/NLnetLabs/dnst
#
LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo cpe ssl
CARGO_ENV+=	OPENSSL_NO_VENDOR=1
CPE_VENDOR=	nlnetlabs
USE_GITHUB=	yes
GH_ACCOUNT=	NLnetLabs

PLIST_FILES=	bin/dnst bin/ldns

.include <bsd.port.mk>
