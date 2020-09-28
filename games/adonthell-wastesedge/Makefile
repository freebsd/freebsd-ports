# Created by: Miguel Mendez <flynn@energyhq.es.eu.org>
# $FreeBSD$
#    $MCom: ports/games/adonthell/Makefile,v 1.1 2006/10/04 20:13:33 ahze Exp $

PORTNAME=	wastesedge
PORTVERSION=	0.3.8
CATEGORIES=	games
MASTER_SITES=	SAVANNAH/adonthell
PKGNAMEPREFIX=	adonthell-
DISTFILES=	${PORTNAME}-src-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Role playing game for the Adonthell engine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	adonthell:games/adonthell
RUN_DEPENDS=	adonthell:games/adonthell

USES=		gettext-tools
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-pyc \
		--with-adonthell-binary=${LOCALBASE}/bin/adonthell

DATADIR=	${PREFIX}/share/adonthell/games/wastesedge
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|test $$adonthell_major_ver -eq 0 .*|true ;|' ${WRKSRC}/configure

.include <bsd.port.mk>
