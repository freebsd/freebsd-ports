# New ports collection makefile for:	p5-Filesys-Virtual-DAAP
# Date created:        27 June 2004
# Whom:                Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Filesys-Virtual-DAAP
PORTVERSION=	0.02
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Filesys
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Present a DAAP share as a VFS

BUILD_DEPENDS=	${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Filesys/Virtual.pm:${PORTSDIR}/devel/p5-Filesys-Virtual \
		${SITE_PERL}/Net/DAAP/Client/Auth.pm:${PORTSDIR}/audio/p5-Net-DAAP-Client-Auth
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Filesys::Virtual::DAAP.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500503
post-patch:
	@${PERL} -pi -e '$$_ = "" if /5.006/' \
		${WRKSRC}/Build.PL
	@${PERL} -pi -e 's/^our ([^\s;]+)/use vars qw($$1); $$1/;' \
		     -e '$$_ = "" if /use warnings/' \
		${WRKSRC}/lib/Filesys/Virtual/DAAP.pm
.endif

.include <bsd.port.post.mk>
