PORTNAME=	yj
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.4
CATEGORIES=	converters textproc
PKGNAMESUFFIX=	-${GH_ACCOUNT}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Command line tool that converts YAML to JSON
WWW=		https://github.com/bruceadams/yj

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	bruceadams

CONFLICTS_INSTALL=	yj

PLIST_FILES=	bin/yj

.include <bsd.port.mk>
