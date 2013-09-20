# $FreeBSD$

PORTNAME=	tkeca
PORTVERSION=	4.4.3
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Tk interface to ecasound

LICENSE=	GPLv2

RUN_DEPENDS=	normalize:${PORTSDIR}/audio/normalize \
		ecasound:${PORTSDIR}/audio/ecasound

USE_GNOME=	desktopfileutils
NO_STAGE=	yes
USE_TCL=	yes
USE_TK=		yes

NO_BUILD=	yes
PORTDOCS=	*

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e '3s,^exec wish,exec ${WISH},' ${WRKSRC}/tkeca.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkeca.tcl ${PREFIX}/bin/tkeca
	${INSTALL_DATA} ${WRKSRC}/tkeca.png ${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/tkeca.desktop ${PREFIX}/share/applications/
	-@update-desktop-database
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tkeca.html ${WRKSRC}/README.tkeca ${DOCSDIR}/
.endif

.include <bsd.port.mk>
