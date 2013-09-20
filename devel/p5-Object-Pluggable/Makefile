# Created by: Jase Thew <freebsd@beardz.net>
# $FreeBSD$

PORTNAME=	Object-Pluggable
PORTVERSION=	1.29
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HINRIK
PKGNAMEPREFIX=	p5-

MAINTAINER=	jase@FreeBSD.org
COMMENT=	A base class for creating plugin-enabled objects

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Object::Pluggable.3 \
		Object::Pluggable::Constants.3 \
		Object::Pluggable::Pipeline.3

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}/
.endif

.include <bsd.port.post.mk>
