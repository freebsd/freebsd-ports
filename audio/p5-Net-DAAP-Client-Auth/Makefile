# New ports collection makefile for:	p5-Net-DAAP-Client-Auth
# Date created:        27 June 2004
# Whom:                Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-DAAP-Client-Auth
PORTVERSION=	0.13
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Extend Net::DAAP::Client to do iTunes authorisation

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5/M4p.pm:${PORTSDIR}/security/p5-Digest-MD5-M4p \
		${SITE_PERL}/Net/DAAP/Client.pm:${PORTSDIR}/audio/p5-dapple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Net::DAAP::Client::Auth.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
post-patch:
	${PERL} -pi -e '$$_ = "" if /5.006/' \
		${WRKSRC}/Build.PL
	${PERL} -pi -e 's/^our ([^\s;]+)/use vars qw($$1); $$1/;' \
		     -e '$$_ = "" if /use warnings/' \
		`${FIND} ${WRKSRC}/lib/Net/DAAP/Client -name \*.pm`
.endif

.include <bsd.port.post.mk>
