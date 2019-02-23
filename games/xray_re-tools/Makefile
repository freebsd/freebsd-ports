# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xray_re-tools
DISTVERSION=	g20180902
CATEGORIES=	games converters

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	X-Ray engine game asset converter (unofficial)

LIB_DEPENDS=	liblzo2.so:archivers/lzo2 \
		libvorbisfile.so:audio/libvorbis \
		libnvtt.so:graphics/nvidia-texture-tools

USE_GITHUB=	yes
GH_ACCOUNT=	abramcumner
GH_TAGNAME=	52721d2

MAKEFILE=	${FILESDIR}/Makefile
BUILD_WRKSRC=	${WRKSRC}/sources
WITHOUT_FBSD10_FIX=	yes

PLIST_FILES=	bin/xr_converter

post-extract:
	@${MV} ${WRKSRC}/sources/3rd\ party ${WRKSRC}/sources/3rd-party
	@${MV} ${WRKSRC}/sources/utils/converter/opcode/Ice/IceTrilist.h \
		${WRKSRC}/sources/utils/converter/opcode/Ice/IceTriList.h
	@${LN} -s StdAfx.h ${WRKSRC}/sources/utils/converter/opcode/Stdafx.h

post-patch:
	@${REINPLACE_CMD} -e '/#include/s,Math,math,' \
	    -e '/#include/s,\.\\Ice\\,Ice/,' \
		${WRKSRC}/sources/utils/converter/opcode/OPC_IceHook.h
	@${REINPLACE_CMD} -e 's,string& version,string version,' \
		${WRKSRC}/sources/utils/converter/level_tools.cxx
	@${REINPLACE_CMD} -e '19s,attenuation1,attenuation2,' \
		${WRKSRC}/sources/xray_re/xr_d3d_light.cxx
	@${REINPLACE_CMD} -e '/OGF3_S_SMPARAMS_VERSION/s,||,\&\&,' \
		${WRKSRC}/sources/xray_re/xr_ogf_v3.cxx
	@${REINPLACE_CMD} -e 's,mP0,mP1,' \
		${WRKSRC}/sources/utils/converter/opcode/Ice/IceLSS.h
	@${REINPLACE_CMD} -e 's,} if,} else if,' \
		${WRKSRC}/sources/utils/converter/level_mesh_ladders.cxx
	@${REINPLACE_CMD} -e 's,push_back,this->&,' \
		${WRKSRC}/sources/xray_re/xr_influence.h
	@${REINPLACE_CMD} -e 's,type_info& type,std::&,' \
		${WRKSRC}/sources/xray_re/xr_scene.cxx
	@${REINPLACE_CMD} -e 's,sprintf_s,xr_snprintf,' \
		${WRKSRC}/sources/xray_re/xr_scene_ways.cxx
	@${REINPLACE_CMD} -e '/return/s,_stricmp,strcasecmp,' \
		${WRKSRC}/sources/xray_re/xr_string_utils.h
	@${REINPLACE_CMD} -e 's,MINGW32__),& || defined(__FreeBSD__),' \
		${WRKSRC}/sources/xray_re/xr_types.h

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/converter \
		${STAGEDIR}${PREFIX}/bin/xr_converter

# Alternative to DOS2UNIX_FILES that preserves original timestamps,
# to be used together with `-l' switch added to PATCH_ARGS below.
fixpatches:
	@${FIND} ${FILESDIR} -name patch-* | ${XARGS} ${SED} -i '' \
		-E 's,[[:cntrl:]]*$$,,'

.include <bsd.port.mk>

PATCH_ARGS+=	-l
