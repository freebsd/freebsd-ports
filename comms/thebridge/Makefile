# Created by: db
# $FreeBSD$

PORTNAME=	thebridge
PORTVERSION=	1.09
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/cqinet/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio Echolink conference bridge

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash

USES=		gmake shebangfix tar:tgz
GNU_CONFIGURE=	yes
PORTDOCS=	README
USE_RC_SUBR=	tbd
MAKE_ARGS=	AUTOMAKE="${TRUE}"

SHEBANG_FILES=	addons/usermgmt.cgi

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=			DOCS READLINE
OPTIONS_DEFAULT=		READLINE

READLINE_CONFIGURE_WITH=	readline
READLINE_USES=			readline

post-patch:
	@${REINPLACE_CMD} 's!tbdcmd=\/usr\/local!tbdcmd=${PREFIX}!'\
		${WRKSRC}/addons/usermgmt.cgi

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/addons/usermgmt.cgi ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/addons/README ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
