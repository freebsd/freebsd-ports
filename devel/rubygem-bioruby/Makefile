# New ports collection makefile for:	rubygem-bioruby
# Date created:		20 June, 2009
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	bioruby
PORTVERSION=	1.4.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG \
		http://rubyforge.org/frs/download.php/73028/
DISTNAME=	bio-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Integrated environment for Bioinformatics written in Ruby

PLIST_FILES=	bin/bioruby \
		bin/br_biofetch.rb \
		bin/br_bioflat.rb \
		bin/br_biogetseq.rb \
		bin/br_pmfetch.rb

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
GEM_NAME=	${DISTNAME}

.include <bsd.port.mk>
