PORTNAME=	slib
PORTVERSION=	3b7 # Keep this in sync with lang/slib
CATEGORIES=	lang scheme
MASTER_SITES=	# empty
PKGNAMESUFFIX=	-${FLAVOR}
DISTFILES=	# empty

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SLIB installation for Guile
WWW=		https://people.csail.mit.edu/jaffer/SLIB.html

BUILD_DEPENDS=	${LOCALBASE}/share/slib/require.scm:lang/slib
RUN_DEPENDS=	${LOCALBASE}/share/slib/require.scm:lang/slib

USES=		guile:1.8,2.2,3.0,flavors,build,run

NO_ARCH=	yes
NO_BUILD=	yes
NO_INSTALL=	yes

SUB_FILES+=	pkg-install pkg-deinstall
SUB_LIST+=	GUILE_VER=${GUILE_VER} \
		SLIB_INIT=${${GUILE_SFX} >= 2:?guile-2.init:guile.init}

.include <bsd.port.mk>
