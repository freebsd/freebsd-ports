# New ports collection makefile for:	p5-JavaScript-SpiderMonkey
# Date created:				25 February 2005
# Whom:	      				kappa@freebsd.org.ua
#
# $FreeBSD$
#

PORTNAME=	JavaScript-SpiderMonkey
PORTVERSION=	0.20
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to Mozilla JavaScript implementation

LIB_DEPENDS=	js.1:${PORTSDIR}/lang/spidermonkey
BUILD_DEPENDS=	${SITE_PERL}/Log/Log4perl.pm:${PORTSDIR}/devel/p5-Log-Log4perl \
		${SITE_PERL}/${PERL_ARCH}/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	INC=-I${LOCALBASE}/include
INSTALL_TARGET=	pure_install

post-patch:
	${REINPLACE_CMD} -e 's~libjs.a~libjs.so~' ${WRKSRC}/Makefile.PL

MAN3=		JavaScript::SpiderMonkey.3

.include <bsd.port.mk>
