PORTNAME=	automake
DISTVERSION=	1.17
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	GNU Standards-compliant Makefile generator
WWW=		https://www.gnu.org/software/automake/

LICENSE=	GPLv2+ GFDL
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_GFDL=	${WRKSRC}/doc/fdl.texi

BUILD_DEPENDS=	autoconf>=2.72:devel/autoconf
RUN_DEPENDS=	autoconf>=2.72:devel/autoconf

USES=		cpe perl5 tar:xz
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes

NO_ARCH=	yes

INFO=		automake automake-history
PLIST_SUB=	BUILD_VERSION=${DISTVERSION:C/(\.[^.]*).*/\1/}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
