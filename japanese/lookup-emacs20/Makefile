# New ports collection makefile for:	lookup for Emacs20
# Date created:		98/11/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lookup
PORTVERSION=	1.2
PKGNAMESUFFIX=	-emacs20
CATEGORIES=	japanese elisp
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/share/emacs/site-lisp/bitmap/bitmap.el:${PORTSDIR}/editors/bitmap-emacs20 \
		${PREFIX}/share/emacs/site-lisp/lookup/lookup.el:${PORTSDIR}/japanese/lookup-mule

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>

