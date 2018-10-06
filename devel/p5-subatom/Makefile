# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	subatom
PORTVERSION=	0.12
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HDM
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Produce an atom feed from subversion commits

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/README

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-XML-Atom-SimpleFeed>=0.80:textproc/p5-XML-Atom-SimpleFeed

NO_ARCH=	yes
USE_PERL5=	modbuild
USES=		perl5

PLIST_FILES=	bin/subatom \
		${SITE_MAN1_REL}/subatom.1.gz

.include <bsd.port.mk>
