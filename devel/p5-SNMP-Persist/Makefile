PORTNAME=	SNMP-Persist
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Backend module for pass_persist feature of Net-SNMP

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if exists(${PERL})
PERL_THREADED!= ${PERL} -mthreads -e '' >/dev/null 2>&1 && ${ECHO_CMD} 'yes' || ${ECHO_CMD}
.  if ${PERL_THREADED} == ""
IGNORE=		must be built with a threaded Perl
.  endif
.endif

.include <bsd.port.post.mk>
