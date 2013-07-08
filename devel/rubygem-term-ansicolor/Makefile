# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	term-ansicolor
PORTVERSION=	1.2.2
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Term::ANSIColor for Ruby

RUN_DEPENDS=	rubygem-tins>=0.8:${PORTSDIR}/devel/rubygem-tins

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES+=	bin/colortab bin/term_display bin/term_mandel

PORTEXAMPLES=	cdiff decolor

.include <bsd.port.options.mk>

post-patch:
# Chop out the cdiff and decolor binaries; these should be installed to
# EXAMPLESDIR
	${REINPLACE_CMD} -e '/^- [cd][de][ic][fo][fl]o*r*$$/d' \
		${WRKSRC}/term-ansicolor-${PORTVERSION}.gemspec

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${PORTEXAMPLES:S,^,${WRKSRC}/bin/,} ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
