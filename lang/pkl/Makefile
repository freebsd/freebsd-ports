PORTNAME=	pkl
DISTVERSION=	0.26.0
CATEGORIES=	lang java
MASTER_SITES=	https://github.com/apple/pkl/releases/download/${PORTVERSION}/
DISTNAME=	jpkl
EXTRACT_SUFX=
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	nyan@myuji.xyz
COMMENT=	Apple's Open Source Configuration as Code language
WWW=		https://pkl-lang.org

LICENSE=	APACHE20

USE_JAVA=	yes
JAVA_VERSION=	17+

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/pkl

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${DIST_SUBDIR}/jpkl ${STAGEDIR}${PREFIX}/bin/pkl

.include <bsd.port.mk>
