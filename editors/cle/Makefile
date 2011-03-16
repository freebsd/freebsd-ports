# New ports collection makefile for:   cle
# Date created:		25 July 2006
# Whom:			Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	cle
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://kaolin.unice.fr/pub/Cle/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command Line Editor (based on readline)

DEPRECATED=	Upstream disapear and distfile is no more available
EXPIRATION_DATE=	2011-05-01

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/cle

MAN1=		cle.1

.include <bsd.port.pre.mk>

post-patch:
	@cd ${WRKSRC} && ${TOUCH} -r configure.in aclocal.m4 \
		Makefile.in */Makefile.in stamp-h.in

.include <bsd.port.post.mk>
