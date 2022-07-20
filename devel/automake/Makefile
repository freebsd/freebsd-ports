PORTNAME=	automake
PORTVERSION=	1.16.5
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	GNU Standards-compliant Makefile generator

LICENSE=	GPLv2+ GFDL
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_GFDL=	${WRKSRC}/doc/fdl.texi

BUILD_DEPENDS=	autoconf>=2.69:devel/autoconf
RUN_DEPENDS=	autoconf>=2.69:devel/autoconf

BUILD_VERSION=	1.16
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
USES=		cpe perl5 tar:xz
GNU_CONFIGURE=	yes
INFO=		automake automake-history
CPE_VENDOR=	gnu

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
