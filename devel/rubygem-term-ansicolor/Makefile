# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	term-ansicolor
PORTVERSION=	1.7.1
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Term::ANSIColor for Ruby

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-tins>=1.0<2:devel/rubygem-tins

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/term_cdiff \
		bin/term_colortab \
		bin/term_decolor \
		bin/term_display \
		bin/term_mandel \
		bin/term_snow

.include <bsd.port.mk>
