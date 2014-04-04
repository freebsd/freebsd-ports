# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elsamuko
DISTVERSION=	0.24
CATEGORIES=	graphics
MASTER_SITES=	https://sites.google.com/site/${PORTNAME}/gimp/
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-script
DISTNAME=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Gimp scripts by elsamuko

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/bin/gimp:${PORTSDIR}/graphics/gimp-app

OPTIONS_DEFINE=	DOCS

USES=		zip
NO_BUILD=	yes

GIMP_SCRIPTS_DIR?=	share/gimp/scripts

# installed dirs
PLIST_DIRSTRY=	${GIMP_SCRIPTS_DIR} \
		share/gimp

# installation dir
PLIST_SUB=	GIMP_SCRIPTS_DIR=${GIMP_SCRIPTS_DIR}

.include <bsd.port.options.mk>

# installed docs
PORTDOCS=	*

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \*.scm \
		${STAGEDIR}${PREFIX}/${GIMP_SCRIPTS_DIR})
# install docs
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/z_README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
