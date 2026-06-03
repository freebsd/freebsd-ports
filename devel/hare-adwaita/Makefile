PORTNAME=	hare-adwaita
DISTVERSION=	0.1.0
CATEGORIES=	devel
MASTER_SITES=	https://git.sr.ht/~${SRHT_ACCOUNT}/${SRHT_PROJECT}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Hare bindings for libadwaita
WWW=		https://git.sr.ht/~sircmpwn/hare-adwaita

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	hare-gi>=0:devel/hare-gi

USES=		gnome
USE_GNOME=	libadwaita

MAKE_ARGS=	DESTDIR=${STAGEDIR} \
		PREFIX=${PREFIX}

PLIST_FILES=	share/hare/third-party/gi/adw/_generated.ha

SRHT_ACCOUNT=	sircmpwn
SRHT_PROJECT=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' ${WRKSRC}/scripts/generate

.include <bsd.port.mk>
