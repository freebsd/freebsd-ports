# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	bioruby
PORTVERSION=	1.4.3.0001
CATEGORIES=	devel rubygems
MASTER_SITES=	RF RG
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
