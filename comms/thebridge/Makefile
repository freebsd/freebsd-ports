# Created by: db
# $FreeBSD$

PORTNAME=	thebridge
PORTVERSION=	1.09
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/cqinet/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio Echolink conference bridge

LICENSE=	GPLv2

USES=		gmake
GNU_CONFIGURE=	yes
PORTDOCS=	README
USE_RC_SUBR=	tbd
MAKE_ARGS=	AUTOMAKE="${TRUE}"

INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}/${DOCSDIR}
.endif
	${MKDIR} ${STAGEDIR}/${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/addons/usermgmt.cgi ${STAGEDIR}/${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/addons/README ${STAGEDIR}/${DATADIR}

.include <bsd.port.mk>
