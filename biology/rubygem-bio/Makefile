# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	bio
PORTVERSION=	1.5.1
CATEGORIES=	biology rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Integrated environment for Bioinformatics written in Ruby

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/bioruby \
		bin/br_biofetch.rb \
		bin/br_bioflat.rb \
		bin/br_biogetseq.rb \
		bin/br_pmfetch.rb

.include <bsd.port.mk>
