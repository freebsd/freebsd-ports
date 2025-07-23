PORTNAME=	pam_wrapper
PORTVERSION=	1.0.6
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SAMBA/cwrap

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool to test PAM applications and PAM modules
WWW=		https://cwrap.org/nss_wrapper.html \
		https://git.samba.org/?p=pam_wrapper.git

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	cmocka>=1.1.1:sysutils/cmocka

USES=		cmake:testing pathfix python

CMAKE_OFF=	UNIT_TESTING
CMAKE_TESTING_ON=	UNIT_TESTING
USE_LDCONFIG=	yes

.include <bsd.port.mk>
