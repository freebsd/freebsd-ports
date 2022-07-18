# Created by: Rod Taylor <ports@rbt.ca>

PORTNAME=	Test-File-Contents
PORTVERSION=	0.24
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}0

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Test routines for examining the contents of files

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Text-Diff>=0.35:textproc/p5-Text-Diff

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
