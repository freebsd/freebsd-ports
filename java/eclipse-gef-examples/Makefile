# Created by: olgeni@FreeBSD.org
# $FreeBSD$

PORTNAME=	gef
PORTVERSION=	3.0
PORTREVISION=	7
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/gef/downloads/drops/R-3.0-200406251257/
PKGNAMEPREFIX=	eclipse-
PKGNAMESUFFIX=	-examples
DISTNAME=	GEF-examples-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical Editing Framework for the Eclipse IDE (examples)

BROKEN=		plugin is obsolete or malfunctioning with latest eclipse
DEPRECATED=	evaluation recommendation is to remove rather than update
EXPIRATION_DATE=	2015-04-18

RUN_DEPENDS=    ${LOCALBASE}/bin/eclipse:${PORTSDIR}/java/eclipse

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	cd ${WRKSRC}/eclipse && ${COPYTREE_SHARE} "features plugins" ${STAGEDIR}${PREFIX}/lib/eclipse

.include <bsd.port.mk>
