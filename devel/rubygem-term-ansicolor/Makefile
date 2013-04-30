# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	term-ansicolor
PORTVERSION=	1.1.4
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Term::ANSIColor for Ruby

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

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
