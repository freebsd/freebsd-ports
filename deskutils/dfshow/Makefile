PORTNAME=	dfshow
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.1-beta
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Directory file editor
WWW=		https://dfshow.op-ezy.co.uk/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libconfig.so:devel/libconfig

USES=		autoreconf gettext-runtime gettext-tools gmake localbase ncurses

USE_GITHUB=	yes
GH_ACCOUNT=	roberthawdon

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

CONFLICTS_INSTALL=	ja-mh mmh nmh nmh-devel # man/man1/show.1.gz

post-patch:
	@${REINPLACE_CMD} 's/-lncursesw/${NCURSESLIBS}/g' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
