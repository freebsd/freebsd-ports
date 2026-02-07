PORTNAME=	xannotate
DISTVERSION=	g20220604
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Turn static CLI commands into TUIs with ease
WWW=		https://github.com/jesseduffield/lazycli

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake localbase xorg
USE_XORG=	x11 xtst

USE_GITHUB=	yes
GH_ACCOUNT=	blais
GH_TAGNAME=	66821cc

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME}

xpost-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
