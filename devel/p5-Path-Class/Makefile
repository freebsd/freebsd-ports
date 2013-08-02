# Created by: Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
# $FreeBSD$

PORTNAME=	Path-Class
PORTVERSION=	0.32
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KWILLIAMS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cross-platform path specification manipulation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS

USES=		perl5
USE_PERL5=	modbuild

MAN3=		Path::Class.3 \
		Path::Class::Dir.3 \
		Path::Class::Entity.3 \
		Path::Class::File.3
PORTDOCS=	Changes README

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
