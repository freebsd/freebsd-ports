# Created by: Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	SNMP-Persist
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	The module is a backend for pass_persist feature of net-snmp

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

PERL_THREADED!= ${PERL} -mthreads -e '' >/dev/null 2>&1 && ${ECHO_CMD} 'yes' || ${ECHO_CMD}
.  if ${PERL_THREADED} == ""
IGNORE=		must be built with a threaded Perl
.  endif

.include <bsd.port.post.mk>
