# Created by: Jonathan Weiss (<jw@innerewut.de>)
# $FreeBSD$

PORTNAME=	rake
PORTVERSION=	10.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby Make

LICENSE=	MIT

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/rake \
		man/man1/rake.1.gz

post-install:
	${INSTALL_MAN} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/doc/rake.1.gz ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
