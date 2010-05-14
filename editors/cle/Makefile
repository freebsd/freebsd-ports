# New ports collection makefile for:   cle
# Date created:		25 July 2006
# Whom:			Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	cle
PORTVERSION=	0.4
CATEGORIES=	editors
MASTER_SITES=	ftp://kaolin.unice.fr/pub/Cle/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command Line Editor (based on readline)

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/cle

MAN1=		cle.1

.include <bsd.port.pre.mk>

post-patch:
	@cd ${WRKSRC} && ${TOUCH} -r configure.in aclocal.m4 \
		Makefile.in */Makefile.in stamp-h.in

.include <bsd.port.post.mk>
