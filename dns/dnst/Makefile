PORTNAME=	dnst
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0-rc2
PORTREVISION=	1
CATEGORIES=	dns net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	DNS administration toolbox including re-implementations of important ldns programs
WWW=		https://github.com/NLnetLabs/dnst
#
LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo cpe ssl
CPE_VENDOR=	nlnetlabs
USE_GITHUB=	yes
GH_ACCOUNT=	NLnetLabs
GH_TAGNAME=	1184e356a

PLIST_FILES=	bin/dnst bin/ldns

.include <bsd.port.mk>
