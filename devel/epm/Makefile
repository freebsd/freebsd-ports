# Created by: NAKATA Maho <maho@FreeBSD.org>

PORTNAME=	epm
PORTVERSION=	4.5.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/michaelrsweet/epm/releases/download/v${PORTVERSION}/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Free UNIX software/file packaging program

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/epm
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/epminstall
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mkepmlist

.include <bsd.port.mk>
