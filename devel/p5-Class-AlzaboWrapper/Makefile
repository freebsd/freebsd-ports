# New ports collection makefile for:	p5-Class-AlzaboWrapper
# Date created:				13 Oct 2004
# Whom:	      				mat
#
# $FreeBSD$
#

PORTNAME=	Class-AlzaboWrapper
PORTVERSION=	0.06
CATEGORIES=	devel databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Class
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Higher level wrapper around Alzabo

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Params/Validate.pm:${PORTSDIR}/devel/p5-Params-Validate \
		${SITE_PERL}//Exception/Class.pm:${PORTSDIR}/devel/p5-Exception-Class \
		${SITE_PERL}/Alzabo.pm:${PORTSDIR}/devel/p5-Alzabo
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Class::AlzaboWrapper.3 Class::AlzaboWrapper::Cursor.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Needs perl 5.6+, install lang/perl5 or lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
