# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	pqiv
PORTVERSION=	2.1
CATEGORIES=	graphics
MASTER_SITES=	GH

DISTNAME=	${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Pretty Quick Image Viewer

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	phillipberndt

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${PORTNAME}-184ef87

OPTIONS_SINGLE=		GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK2

USES=		gmake pkgconfig shebangfix
SHEBANG_FILES=	configure
USE_BZIP2=	yes
HAS_CONFIGURE=	yes

GTK2_CONFIGURE_ON=	--gtk-version=2
GTK2_USE=		GNOME=gtk20

GTK3_CONFIGURE_ON=	--gtk-version=3
GTK3_USE=		GNOME=gtk30

PORTDOCS=	README.markdown
PLIST_FILES=	bin/pqiv man/man1/pqiv.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pqiv ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pqiv.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
