# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$
#    $MCom: ports/lang/slib-guile/Makefile,v 1.3 2006/10/13 02:32:48 marcus Exp $

PORTNAME=	slib
PORTVERSION=	3b6 # Keep this in sync with lang/slib
CATEGORIES=	lang scheme
MASTER_SITES=	# empty
PKGNAMESUFFIX=	-guile1
DISTFILES=	# empty

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	SLIB installation for Guile1

BUILD_DEPENDS=	${LOCALBASE}/share/slib/require.scm:lang/slib \
		guile:lang/guile1
RUN_DEPENDS:=	${BUILD_DEPENDS}

SUB_FILES+=	pkg-install pkg-deinstall
NO_ARCH=	yes
NO_BUILD=	yes
NO_INSTALL=	yes

.include <bsd.port.mk>
