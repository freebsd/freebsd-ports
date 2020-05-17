# $FreeBSD$

PORTNAME=	wxformbuilder
DISTVERSION=	3.5.0-beta
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-nightly/${DISTVERSION}
DISTNAME=	wxFormBuilder_v${DISTVERSION}-source

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	WYSIWYG GUI Designer and Code Generator for wxWidgets

LICENSE=	GPLv2

USES=		compiler:c++11-lib dos2unix gmake zip
USE_CSTD=	c++11
USE_LDCONFIG=	yes
USE_WX=		3.0+
WRKSRC=		${WRKDIR}/source
MAKE_ARGS=	config=release ARCH=
BUILD_WRKSRC=	${WRKSRC}/build/${WX_VERSION}/gmake
DOS2UNIX_GLOB=	*.lua

do-configure:
	cd ${WRKSRC} && ${SH} create_build_files4.sh

post-patch:
	@${REINPLACE_CMD} -e 's|%%WX_CONFIG%%|${WX_CONFIG}|g' ${WRKSRC}/build/premake/wxwidgets.lua \
		${WRKSRC}/create_build_files4.sh ${WRKSRC}/sdk/plugin_interface/premake.lua \
		${WRKSRC}/sdk/premake/scripts/wxpresets.lua

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/wxformbuilder
	(cd ${WRKSRC}/output && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	(cd ${STAGEDIR}${DATADIR}/bin && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/bin)
	${RM} -r ${STAGEDIR}${DATADIR}/bin/
	(cd ${STAGEDIR}${DATADIR}/lib && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/lib)
	${RM} -r ${STAGEDIR}${DATADIR}/lib/
	${RM} -r ${STAGEDIR}${DATADIR}/share/
	${RM} ${STAGEDIR}${DATADIR}/license.txt
	${RM} ${STAGEDIR}${DATADIR}/Changelog.txt

.include <bsd.port.mk>
