# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jagged-border
PORTVERSION=	0.2009.11.12
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://registry.gimp.org/files/
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-scripts
DISTNAME=	script-fu-jagged-border.scm
EXTRACT_SUFX=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GIMP script to create a jagged border around an image

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/bin/gimp:${PORTSDIR}/graphics/gimp-app

USES=		dos2unix
NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

GIMP_SCRIPTS_DIR?=	share/gimp/scripts

PLIST_FILES=	${GIMP_SCRIPTS_DIR}/${DISTNAME}

post-extract:
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${GIMP_SCRIPTS_DIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} ${STAGEDIR}${PREFIX}/${GIMP_SCRIPTS_DIR}/

.include <bsd.port.mk>
