# New ports collection makefile for:	Params::CallbackRequest
# Date created:				21 May 2004
# Whom:					Rod Taylor <ports@rbt.ca>
#
# $FreeBSD$
#

PORTNAME=	Params-CallbackRequest
PORTVERSION=	1.13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Params/DWHEELER
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@rbt.ca
COMMENT=	Provide callbacks to method and function parameters

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}/Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Params::Callback.3 Params::CallbackRequest.3 \
		Params::CallbackRequest::Exceptions.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -i -pe 's/(sub \S+) : .+ {/$$1 {/g' ${WRKSRC}/lib/Params/Callback.pm
.endif

.include <bsd.port.post.mk>
