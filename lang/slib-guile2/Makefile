# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$

PORTNAME=	slib
PORTVERSION=	3b4 # Keep this in sync with lang/slib
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	# empty
PKGNAMESUFFIX=	-guile2
DISTFILES=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SLIB installation for Guile

BUILD_DEPENDS=	${LOCALBASE}/share/slib/require.scm:lang/slib \
		guile:lang/guile2
RUN_DEPENDS:=	${BUILD_DEPENDS}

SUB_FILES+=	pkg-install pkg-deinstall
NO_BUILD=	yes
NO_INSTALL=	yes

.include <bsd.port.mk>
