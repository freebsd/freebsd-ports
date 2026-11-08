PORTNAME=	tobi-try
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.1
CATEGORIES=	devel

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Fresh directories for every vibe
WWW=		https://github.com/tobi/try

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ruby:run shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	tobi
GH_PROJECT=	try
SHEBANG_FILES=	try.rb

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/try \
		${DATADIR_REL}/lib/fuzzy.rb \
		${DATADIR_REL}/lib/tui.rb \
		${DATADIR_REL}/try.rb

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/try.rb ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/fuzzy.rb ${WRKSRC}/lib/tui.rb \
		${STAGEDIR}${DATADIR}/lib
	${RLN} ${STAGEDIR}${DATADIR}/try.rb ${STAGEDIR}${PREFIX}/bin/try

.include <bsd.port.mk>
