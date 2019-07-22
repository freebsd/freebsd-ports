# $FreeBSD$

PORTNAME=	lolcat
PORTVERSION=	99.9.99
CATEGORIES=	games
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rainbows and unicorns

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-manpages>=0.6.1:devel/rubygem-manpages \
		rubygem-optimist>=3.0.0:devel/rubygem-optimist \
		rubygem-paint>=2.0.0:devel/rubygem-paint

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/lolcat \
		man/man6/lolcat.6.gz

post-build:
	@${REINPLACE_CMD} -e 's|man/lolcat.6|&.gz|' ${WRKSRC}/${GEMSPEC}

# compress the manpage manually instead of MANDIRS because of the order in
# _STAGE_SEQ: 820:gem-autoplist 850:compress-man
post-install:
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/man/lolcat.6

.include <bsd.port.mk>
