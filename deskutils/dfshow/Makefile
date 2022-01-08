PORTNAME=	dfshow
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.4-beta
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Directory file editor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libconfig.so:devel/libconfig

USES=		autoreconf gmake localbase ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	roberthawdon

GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} 's/-lncursesw/${NCURSESLIBS}/g' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
