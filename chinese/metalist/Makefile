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
COMMENT=	A Chinese port of Slash-Like Automatic Storytelling Homepage system

BUILD_DEPENDS=	${LOCALBASE}/bin/safe_mysqld:${PORTSDIR}/databases/mysql323-server \
		${SITE_PERL}/Bundle/Slash.pm:${PORTSDIR}/www/p5-Bundle-Slash \
		${SITE_PERL}/Test/Harness.pm:${PORTSDIR}/devel/p5-Test-Harness \
		${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl

LIB_PERL=	${LOCALBASE}/lib/perl5/${PERL_VER}
DOCS=		README README.metalist INSTALL

CONFLICTS=	slash

post-install:
	@${SED} s!%%LOCALBASE%%!${LOCALBASE}!g ${PKGMESSAGE}

.include <bsd.port.pre.mk>

pre-everything::
.if ${PERL_LEVEL} < 500601
BROKEN=        metalist only supports the ports versions of Perl.
BROKEN+=If you have installed a Perl port, and are getting this message,
BROKEN+=please make sure you have given the command \'use.perl port\'
.endif # ${PERL_LEVEL} < 500601

.include <bsd.port.post.mk>
