PORTNAME=	hare-gtk4-layer-shell
DISTVERSION=	0.1.0
CATEGORIES=	devel
MASTER_SITES=	https://git.sr.ht/~${SRHT_ACCOUNT}/${SRHT_PROJECT}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	gtk4-layer-shell bindings for Hare
WWW=		https://git.sr.ht/~sircmpwn/hare-gtk4-layer-shell

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	hare-gi>=0:devel/hare-gi
LIB_DEPENDS=	libgtk4-layer-shell.so:x11-toolkits/gtk4-layer-shell

MAKE_ARGS=	DESTDIR=${STAGEDIR} \
		PREFIX=${PREFIX}

PLIST_FILES=	share/hare/third-party/gi/gtk4_layer_shell/_generated.ha

SRHT_ACCOUNT=	sircmpwn
SRHT_PROJECT=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' ${WRKSRC}/scripts/generate

.include <bsd.port.mk>
