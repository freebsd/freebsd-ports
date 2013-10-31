# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	Proc-ProcessTable
PORTVERSION=	0.48
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JWB
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the unix process table

USES=		perl5
USE_PERL5=	configure

PORTDOCS=	README README.freebsd-kvm README.freebsd-procfs

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
