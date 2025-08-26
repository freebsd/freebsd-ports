PORTNAME=	gcc
PORTVERSION=	${GCC_DEFAULT}
PORTREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	# not applicable
DISTFILES=	# not applicable

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Meta-port for the default version of the GNU Compiler Collection
WWW=		https://gcc.gnu.org

RUN_DEPENDS=	gcc${GCC_DEFAULT}:lang/gcc${GCC_DEFAULT}

USES=		cpe
CPE_VENDOR=	gnu
CPE_VERSION=	${GCC_DEFAULT}

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/g++ bin/gcc bin/gfortran

do-install:
.for c in gfortran g++ gcc
	    ${LN} -s ${c}${GCC_DEFAULT} ${STAGEDIR}${PREFIX}/bin/${c}
.endfor

.include <bsd.port.mk>
