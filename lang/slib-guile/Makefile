# New ports collection makefile for:	SLIB for Guile
# Date created:                3 November 2003
# Whom:                        Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	slib
PORTVERSION=	3a1 # Keep this in sync with lang/slib
CATEGORIES=	lang scheme
MASTER_SITES=	# empty
PKGNAMESUFFIX=	-guile
DISTFILES=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SLIB installation for Guile

BUILD_DEPENDS=	${LOCALBASE}/share/slib/require.scm:${PORTSDIR}/lang/slib \
		guile:${PORTSDIR}/lang/guile
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes

do-install:
	${LN} -shf ${PREFIX}/share/slib ${LOCALBASE}/share/guile/slib
	${LOCALBASE}/bin/guile -c \
		"(use-modules (ice-9 slib)) (require 'new-catalog)"

.include <bsd.port.mk>
