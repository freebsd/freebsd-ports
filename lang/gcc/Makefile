PORTNAME=	gcc
PORTVERSION=	${GCC_DEFAULT}
PORTREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	# not applicable
DISTFILES=	# not applicable

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Meta-port for the default version of the GNU Compiler Collection

# Once GCC 4.8 isn't an option any longer, we can simply use GCC_DEFAULT
# below. (The expression rewrites 4.8 to 48.)
RUN_DEPENDS=	gcc${GCC_DEFAULT:S/.//}:lang/gcc${GCC_DEFAULT:S/.//}

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
