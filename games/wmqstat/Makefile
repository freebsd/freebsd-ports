PORTNAME=	wmqstat
PORTVERSION=	0.0.4
PORTREVISION=	3
CATEGORIES=	games windowmaker
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/wmQStat%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp for monitoring of various Internet game servers
WWW=		https://wmqstat.sourceforge.net/

LICENSE=	GPLv2

RUN_DEPENDS=	qstat:games/qstat

USES=		xorg
USE_XORG=	xpm x11 xext

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
