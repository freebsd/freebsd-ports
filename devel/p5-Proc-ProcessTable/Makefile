# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	Proc-ProcessTable
PORTVERSION=	0.50
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JWB
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the unix process table

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS

USES=		perl5 shebangfix
USE_PERL5=	configure

PORTDOCS=	README README.freebsd-kvm README.freebsd-procfs

SHEBANG_FILES=	example.pl

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
