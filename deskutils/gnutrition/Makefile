PORTNAME=	gnutrition
DISTVERSION=	0.33
CATEGORIES=	deskutils
MASTER_SITES=	GNU

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Free nutrition tracker software
WWW=		http://www.gnu.org/software/gnutrition/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext-runtime gmake gnome pkgconfig sqlite tar:xz
USE_GNOME=	glib20 gtk30

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gnutrition ${DATADIR}/food.db
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
