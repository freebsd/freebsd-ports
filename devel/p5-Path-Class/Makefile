# New ports collection makefile for:	Path::Class
# Date created:		2004-07-25
# Whom:			Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Path-Class
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/K/KW/KWILLIAMS/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cross-platform path specification manipulation

PERL_MODBUILD=	yes

MAN3=		Path::Class.3 \
		Path::Class::File.3 \
		Path::Class::Dir.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
EXTRA_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/IO/Dir.pm:${PORTSDIR}/devel/p5-IO \
		${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
BUILD_DEPENDS=	${EXTRA_DEPENDS}
RUN_DEPENDS=	${EXTRA_DEPENDS}
.endif

.include <bsd.port.post.mk>
