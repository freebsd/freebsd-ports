# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elsamuko
DISTVERSION=	0.24
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://sites.google.com/site/${PORTNAME}/gimp/
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-script
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gimp scripts by elsamuko

LICENSE=	GPLv3

BROKEN=		No public distfiles

RUN_DEPENDS=	${LOCALBASE}/bin/gimp:${PORTSDIR}/graphics/gimp-app

OPTIONS_DEFINE=	DOCS

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes

GIMP_SCRIPTS_DIR?=	share/gimp/scripts

# installation dir
PLIST_SUB=	GIMP_SCRIPTS_DIR=${GIMP_SCRIPTS_DIR}

# installed docs
PORTDOCS=	*

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \*.scm \
		${STAGEDIR}${PREFIX}/${GIMP_SCRIPTS_DIR})

# install docs
do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/z_README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
