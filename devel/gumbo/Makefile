PORTNAME=	gumbo
DISTVERSION=	0.13.2
PORTREVISION=	1
CATEGORIES=	devel textproc
MASTER_SITES=	https://codeberg.org/gumbo-parser/gumbo-parser/archive/${DISTVERSION}${EXTRACT_SUFX}?dummy/

MAINTAINER=	fsbruva@yahoo.com
COMMENT=	Pure-C HTML5 parser
WWW=		https://codeberg.org/gumbo-parser/gumbo-parser/

LICENSE=	APACHE20

USES=		autoreconf gmake libtool pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/gumbo-parser

.include <bsd.port.mk>
