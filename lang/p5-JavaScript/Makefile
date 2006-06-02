# New ports collection makefile for:	p5-JavaScript
# Date created:				02 June 2006
# Whom:	      				dom@happygiraffe.net
#
# $FreeBSD$
#

PORTNAME=	JavaScript
PORTVERSION=	0.55
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	JavaScript
PKGNAMEPREFIX=	p5-

MAINTAINER=	dom@happygiraffe.net
COMMENT=	Perl extension for executing embedded JavaScript

BUILD_DEPENDS=	${LOCALBASE}/lib/libjs.so:${PORTSDIR}/lang/spidermonkey
RUN_DEPENDS=	${BUILD_DEPENDS}

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
