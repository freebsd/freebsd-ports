# New ports collection makefile for:	p5-JavaScript-SpiderMonkey
# Date created:				25 February 2005
# Whom:	      				kappa@freebsd.org.ua
#
# $FreeBSD$
#

PORTNAME=	JavaScript-SpiderMonkey
PORTVERSION=	0.16
CATEGORIES=	lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	JavaScript
PKGNAMEPREFIX=	p5-

MAINTAINER=	kappa@freebsd.org.ua
COMMENT=	Perl interface to Mozilla JavaScript implementation

LIB_DEPENDS=	js.1:${PORTSDIR}/lang/spidermonkey
BUILD_DEPENDS=	${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INC=-I${LOCALBASE}/include
INSTALL_TARGET=	pure_install

post-patch:
	${REINPLACE_CMD} -e 's~libjs.a~libjs.so~' ${WRKSRC}/Makefile.PL

MAN3=		JavaScript::SpiderMonkey.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000 #inherited from lang/spidermonkey
BROKEN=	does not compile on FreeBSD 4.x
.endif

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
