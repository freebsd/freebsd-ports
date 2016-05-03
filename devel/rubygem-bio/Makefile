# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	bio
PORTVERSION=	1.4.3.0001
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Integrated environment for Bioinformatics written in Ruby

LICENSE=	GPLv2 RUBY
LICENSE_COMB=	dual

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	sample/biofetch.rb
ruby_OLD_CMD=	/usr/proj/bioruby/bin/ruby

PLIST_FILES=	bin/bioruby \
		bin/br_biofetch.rb \
		bin/br_bioflat.rb \
		bin/br_biogetseq.rb \
		bin/br_pmfetch.rb

.include <bsd.port.mk>
