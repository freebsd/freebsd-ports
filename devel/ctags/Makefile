# New ports collection makefile for:   exctags
# Date created:        4 June 1996
# Whom:                jkoshy
#
# $FreeBSD$
#

PORTNAME=	ctags
PORTVERSION=	5.0
CATEGORIES=	devel
MASTER_SITES=	http://ctags.sourceforge.net/archives/ \
		${MASTER_SITE_SUNSITE} \
		http://fly.hiwaay.net/~darren/archives/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	devel/lang/c jkoshy

MAINTAINER=	jkoshy@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-macro-patterns --disable-etags

MAN1=		exctags.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ctags ${PREFIX}/bin/exctags
	${INSTALL_MAN} ${WRKSRC}/ctags.1 ${PREFIX}/man/man1/exctags.1

.include <bsd.port.mk>
