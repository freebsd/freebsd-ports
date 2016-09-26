# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	List-MoreUtils
DISTVERSION=	0.416
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:REHSACK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide the stuff missing in List::Util

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Exporter-Tiny>=0.038:devel/p5-Exporter-Tiny \
		p5-XSLoader>=0.22:devel/p5-XSLoader
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-stage:
	( \
		cd ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/List/MoreUtils; \
		${CHMOD} u+w MoreUtils.so; \
		${STRIP_CMD} MoreUtils.so; \
		${CHMOD} u-w MoreUtils.so; \
	)

.include <bsd.port.mk>
