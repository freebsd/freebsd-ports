PORTNAME=	symbiyosys
DISTVERSIONPREFIX=	yosys-
DISTVERSION=	0.44
CATEGORIES=	cad
PKGNAMEPREFIX=

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SymbiYosys (sby): Front-end for Yosys-based formal verification flows
WWW=		https://yosyshq.readthedocs.io/projects/sby/en/latest/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	yosys:cad/yosys

USES=		gmake python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	YosysHQ
GH_PROJECT=	sby

SHEBANG_FILES=	sbysrc/sby.py

NO_BUILD=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
