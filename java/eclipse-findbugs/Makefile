PORTNAME=	findbugs
DISTVERSION=	3.0.1.20150306-5afe4d1
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20eclipse%20plugin/3.0.1
PKGNAMEPREFIX=	eclipse-
DISTNAME=	edu.umd.cs.findbugs.plugin.eclipse_${DISTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Eclipse plug-in that provides FindBugs support
WWW=		https://findbugs.sourceforge.net/manual/eclipse.html

RUN_DEPENDS=	eclipse:java/eclipse

USES=		java zip
NO_BUILD=	yes
JAVA_OS=	native

PLIST_SUB=	\
	ECLIPSE_PLUGINS="lib/eclipse/plugins" \
	DISTNAME="${DISTNAME}"

post-extract:
	@${RM} -R ${WRKSRC}/src

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/eclipse/plugins/${DISTNAME})

.include <bsd.port.mk>
