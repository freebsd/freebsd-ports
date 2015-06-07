# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	term-ansicolor
PORTVERSION=	1.3.0
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Term::ANSIColor for Ruby

LICENSE=	GPLv2

RUN_DEPENDS=	rubygem-tins>=1.0:${PORTSDIR}/devel/rubygem-tins

OPTIONS_DEFINE=	EXAMPLES

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/colortab bin/term_display bin/term_mandel
PORTEXAMPLES=	cdiff decolor

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/bin/ && ${INSTALL_SCRIPT} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
