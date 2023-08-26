PORTNAME=	shflags
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Command-line flags module for Unix shell scripts
WWW=		https://github.com/kward/shflags

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	bash:shells/bash \
		dash:shells/dash \
		ksh93:shells/ksh \
		mksh:shells/mksh \
		zsh:shells/zsh

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	lib/shflags

GH_ACCOUNT=	kward
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/test_runner

do-install:
	${INSTALL_DATA} ${WRKSRC}/shflags ${STAGEDIR}${PREFIX}/lib/

do-test:
	cd ${WRKSRC} && ${SH} test_runner

.include <bsd.port.mk>
