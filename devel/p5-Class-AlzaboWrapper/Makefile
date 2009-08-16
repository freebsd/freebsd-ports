# New ports collection makefile for:	p5-Class-AlzaboWrapper
# Date created:				13 Oct 2004
# Whom:	      				mat
#
# $FreeBSD$
#

PORTNAME=	Class-AlzaboWrapper
PORTVERSION=	0.14
CATEGORIES=	devel databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Higher level wrapper around Alzabo Row and Table objects

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

.include <bsd.port.mk>
