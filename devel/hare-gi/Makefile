PORTNAME=	hare-gi
DISTVERSION=	0.1.0
CATEGORIES=	devel
MASTER_SITES=	https://git.sr.ht/~${SRHT_ACCOUNT}/${SRHT_PROJECT}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	GObject Introspection code generator for Hare
WWW=		https://sr.ht/~yerinalexey/hare-gi

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	hare-lang>=0:devel/hare
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene

USES=		gnome
USE_GNOME=	atk gdkpixbuf glib20 gtk30 gtk40 introspection pango

MAKE_ARGS=	DESTDIR=${STAGEDIR} \
		PREFIX=${PREFIX}

SRHT_ACCOUNT=	yerinalexey
SRHT_PROJECT=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' ${WRKSRC}/scripts/generate-gtk3
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' ${WRKSRC}/scripts/generate-gtk4

.include <bsd.port.mk>
