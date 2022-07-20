PORTNAME=	slib
PORTVERSION=	3b6 # Keep this in sync with lang/slib
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	# empty
PKGNAMESUFFIX=	-guile
DISTFILES=	# empty

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SLIB installation for Guile

BUILD_DEPENDS=	${LOCALBASE}/share/slib/require.scm:lang/slib \
		guile:lang/guile
RUN_DEPENDS:=	${BUILD_DEPENDS}

SUB_FILES+=	pkg-install pkg-deinstall
NO_ARCH=	yes
NO_BUILD=	yes
NO_INSTALL=	yes

.include <bsd.port.mk>
