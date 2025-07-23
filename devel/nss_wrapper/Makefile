PORTNAME=	nss_wrapper
PORTVERSION=	1.1.3
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SAMBA/cwrap

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrapper for the user, group and hosts NSS API
WWW=		https://cwrap.org/nss_wrapper.html \
		https://git.samba.org/?p=nss_wrapper.git

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	cmocka>=1.1.1:sysutils/cmocka

USES=		cmake:testing pathfix perl5 shebangfix
USE_PERL5=	run

CMAKE_OFF=	UNIT_TESTING
CMAKE_TESTING_ON=	UNIT_TESTING
USE_LDCONFIG=	yes

SHEBANG_FILES=	nss_wrapper.pl

.include <bsd.port.mk>
