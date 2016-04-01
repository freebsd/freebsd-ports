# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$
#    $MCom: ports/lang/slib-guile/Makefile,v 1.3 2006/10/13 02:32:48 marcus Exp $

PORTNAME=	slib
PORTVERSION=	3b4 # Keep this in sync with lang/slib
CATEGORIES=	lang scheme
MASTER_SITES=	# empty
PKGNAMESUFFIX=	-guile
DISTFILES=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SLIB installation for Guile

BUILD_DEPENDS=	${LOCALBASE}/share/slib/require.scm:lang/slib \
		guile:lang/guile
RUN_DEPENDS:=	${BUILD_DEPENDS}

SUB_FILES+=	pkg-install pkg-deinstall
NO_BUILD=	yes
NO_INSTALL=	yes

.include <bsd.port.mk>
