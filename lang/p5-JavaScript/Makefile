# New ports collection makefile for:	p5-JavaScript
# Date created:				02 June 2006
# Whom:	      				dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	JavaScript
PORTVERSION=	0.55
PORTREVISION=	1
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	JavaScript
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension for executing embedded JavaScript

LIB_DEPENDS=	js.1:${PORTSDIR}/lang/spidermonkey

MAN3=		JavaScript.3

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INC=-I${LOCALBASE}/include

post-patch:
	${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/' ${WRKSRC}/JavaScript.xs

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		a dependency does not compile on FreeBSD 4.x
.endif

.include <bsd.port.post.mk>
