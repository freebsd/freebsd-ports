# New ports collection makefile for:	metalist
# Date created:				18 March 2002
# Whom:					Autrijus Tang
#
# $FreeBSD$
#

PORTNAME=	metalist
PORTVERSION=	2.2.6
CATEGORIES=	chinese www
MASTER_SITES=	http://p4.elixus.org/dist/
DISTNAME=	metalist-${PORTVERSION}

MAINTAINER=	autrijus@autrijus.org

BUILD_DEPENDS=	${LOCALBASE}/bin/safe_mysqld:${PORTSDIR}/databases/mysql323-server \
		${SITE_PERL}/Bundle/Slash.pm:${PORTSDIR}/www/p5-Bundle-Slash \
		${LIB_PERL}/Test/Harness.pm:${PORTSDIR}/devel/p5-Test-Harness \
		${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl

LIB_PERL=	${LOCALBASE}/lib/perl5/${PERL_VER}
SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

DOCS=		README README.metalist INSTALL

post-install:
	@${SED} s!%%LOCALBASE%%!${LOCALBASE}!g ${PKGMESSAGE}

.include <bsd.port.mk>
