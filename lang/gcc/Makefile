# Created by: Gerald Pfeifer <gerald@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	${GCC_DEFAULT}
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	# not applicable
DISTFILES=	# not applicable

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Meta-port for the default version of the GNU Compiler Collection

# Once GCC 4.9 and 4.8 aren't options any longer, we can simply use
# GCC_DEFAULT again below (the expression rewrites 4.9 to 49).
RUN_DEPENDS=	gcc${GCC_DEFAULT:S/.//}:lang/gcc${GCC_DEFAULT:S/.//}

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/g++ bin/gcc bin/gfortran

do-install:
.for c in gfortran g++ gcc
	    ${LN} -s ${c}${GCC_DEFAULT} ${STAGEDIR}${PREFIX}/bin/${c}
.endfor

.include <bsd.port.mk>
