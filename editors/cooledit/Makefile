PORTNAME=	cooledit
DISTVERSION=	3.17.28
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	SUNSITE/apps/editors/X/cooledit

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	CoolEdit Programmers Code Editor
WWW=		https://github.com/paulsheer/cooledit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext-runtime libtool:build python xorg # gettext is linked to despite .mo files having been deleted
USE_LDCONFIG=	yes
USE_XORG=	x11 xt

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

LDFLAGS+=	-lpthread

OPTIONS_DEFINE=			NEXT_LOOK
NEXT_LOOK_DESC=			Enable NeXT look
NEXT_LOOK_CONFIGURE_ENABLE=	NeXT-look

post-patch:
	@${REINPLACE_CMD} -e 's|po pixmap man|po man|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
