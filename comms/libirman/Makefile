PORTNAME=	libirman
PORTVERSION=	0.5.2
CATEGORIES=	comms
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for Evation's Irman infrared receiver
WWW=		https://libirman.sourceforge.io/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool pkgconfig

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

DOCS=	AUTHORS ChangeLog README TECHNICAL TODO

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
