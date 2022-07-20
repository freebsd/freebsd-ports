PORTNAME=	bio-executables
PORTVERSION=	1.0.0
CATEGORIES=	biology rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of miscellaneous utilities for bioinformatics

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-bio>=2.0.0:biology/rubygem-bio \
		rubygem-bio-old-biofetch-emulator>=0.0.1:biology/rubygem-bio-old-biofetch-emulator

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/br_biofetch.rb \
		bin/br_bioflat.rb \
		bin/br_biogetseq.rb \
		bin/br_pmfetch.rb

.include <bsd.port.mk>
