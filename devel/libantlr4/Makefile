PORTNAME=	antlr4
PORTVERSION=	4.9.3
DISTVERSIONPREFIX=	cpp-runtime-
DISTVERSIONSUFFIX=	-source
CATEGORIES=	devel
MASTER_SITES=	http://www.antlr.org/download/
PKGNAMEPREFIX=		lib

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	ANother Tool for Language Recognition (C runtime)

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	utf8cpp>0:devel/utf8cpp

USES=		cmake compiler:c11 zip
NO_WRKSUBDIR=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
LIBVERSION=	${PORTVERSION}
PLIST_SUB+=	LIBVERSION=${PORTVERSION}

.include <bsd.port.mk>
