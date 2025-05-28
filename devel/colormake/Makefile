PORTNAME=	colormake
PORTVERSION=	0.9.20140503
CATEGORIES=	devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Wrapper around GNU make to colorize output
WWW=		https://github.com/pagekite/Colormake

LICENSE=	GPLv2+

RUN_DEPENDS=	gmake:devel/gmake \
		bash:shells/bash

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	pagekite
GH_PROJECT=	Colormake
USE_PERL5=	run
SHEBANG_FILES=	colormake.pl

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/clmake bin/clmake-short bin/colormake \
		bin/colormake-short bin/colormake.pl \
		share/man/man1/colormake.1.gz
PORTDOCS=	AUTHORS BUGS ChangeLog README

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's,make ,g&, ; s,/bin/bash,${LOCALBASE}&,' \
		${WRKSRC}/colormake

do-install:
	cd ${WRKSRC} && \
	${INSTALL_SCRIPT} colormake.pl colormake ${STAGEDIR}${PREFIX}/bin
.for another_name in clmake clmake-short colormake-short
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} colormake ${another_name}
.endfor
	${INSTALL_MAN} ${WRKSRC}/colormake.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
