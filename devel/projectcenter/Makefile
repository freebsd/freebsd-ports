PORTNAME=	projectcenter
PORTVERSION=	0.6.2
PORTREVISION=	7
CATEGORIES=	devel gnustep
MASTER_SITES=	GNUSTEP/dev-apps
DISTNAME=	ProjectCenter-${PORTVERSION}

PATCH_SITES=	https://github.com/gnustep/apps-projectcenter/commit/
PATCHFILES=	97aa34218f0370ba8b672d3f905df0ed8de9ac8.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Development environment for GNUstep
WWW=		http://www.gnustep.org/experience/ProjectCenter.html

LICENSE=	GPLv2+ # comment in code; COPYING says GPLv3

USES=		gnustep
USE_GNUSTEP=	back build
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

PLIST_SUB+=	FRAMEVERSION=${PORTVERSION}

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/ProjectCenter.app/ProjectCenter \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/ProjectCenter.app/Resources/Aggregate.project/Aggregate \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/ProjectCenter.app/Resources/Application.project/Application \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/ProjectCenter.app/Resources/Build.preferences/Build \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/ProjectCenter.app/Resources/Bundle.project/Bundle \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/ProjectCenter.app/Resources/EditorFSC.preferences/EditorFSC \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/ProjectCenter.app/Resources/Framework.project/Framework \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/ProjectCenter.app/Resources/Library.project/Library \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/ProjectCenter.app/Resources/Misc.preferences/Misc \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/ProjectCenter.app/Resources/ProjectCenter.debugger/ProjectCenter \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/ProjectCenter.app/Resources/ProjectCenter.editor/ProjectCenter \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/ProjectCenter.app/Resources/ProjectCenter.parser/ProjectCenter \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/ProjectCenter.app/Resources/ResourceSet.project/ResourceSet \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/ProjectCenter.app/Resources/Saving.preferences/Saving \
		${STAGEDIR}${PREFIX}/GNUstep/System/Applications/ProjectCenter.app/Resources/Tool.project/Tool \
		${STAGEDIR}${PREFIX}/GNUstep/System/Library/Frameworks/ProjectCenter.framework/Versions/${PORTVERSION}/libProjectCenter.so

.include <bsd.port.mk>
