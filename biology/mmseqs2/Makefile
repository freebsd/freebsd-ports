PORTNAME=	MMseqs2
DISTVERSION=	13-45111
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Ultra fast and sensitive sequence search and clustering suite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake perl5 shebangfix

SHEBANG_GLOB=	*.sh

USE_GITHUB=	yes
GH_ACCOUNT=	soedinglab

PLIST_FILES=	bin/mmseqs ${DATADIR}/bash-completion.sh

post-patch:
	@${REINPLACE_CMD} -e 's|MMSEQS_HOME/util|${DATADIR}|g' \
		${WRKSRC}/src/commons/Application.cpp

post-stage:
	${MV} ${STAGEDIR}${PREFIX}/util ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
