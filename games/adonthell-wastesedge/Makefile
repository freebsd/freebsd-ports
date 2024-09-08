PORTNAME=	wastesedge
PORTVERSION=	0.3.8
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SAVANNAH/adonthell
PKGNAMEPREFIX=	adonthell-
DISTFILES=	${PORTNAME}-src-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Role playing game for the Adonthell engine
WWW=		https://adonthell.nongnu.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on deprecated port games/adonthell
EXPIRATION_DATE=2024-09-30

BUILD_DEPENDS=	adonthell:games/adonthell
RUN_DEPENDS=	adonthell:games/adonthell

USES=		gettext-tools
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--disable-pyc \
		--with-adonthell-binary=${LOCALBASE}/bin/adonthell

DATADIR=	${PREFIX}/share/adonthell/games/wastesedge
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|test $$adonthell_major_ver -eq 0 .*|true ;|' ${WRKSRC}/configure

.include <bsd.port.mk>
