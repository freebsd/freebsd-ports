# ex:ts=8
# Ports collection makefile for:	libv3d
# Date Created:			Jul 2, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libv3d
PORTVERSION=	0.1.14
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://wolfpack.twu.net/users/wolfpack/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	V3D IO Library

USE_REINPLACE=	yes
USE_MESA=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	UNIX --prefix=${PREFIX}
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN3=	V3DGLInterpriteDelete.3 \
	V3DGLInterpriteNew.3 \
	V3DGLProcessModel.3 \
	V3DGLProcessModelExtra.3 \
	V3DGLResourceDelete.3 \
	V3DGLResourceGetInterpritation.3 \
	V3DGLResourceNew.3 \
	V3DGLResourceNewFromModelData.3 \
	V3DGLResourceSetInterpritation.3 \
	V3DHFGetHeightFromWorldPosition.3 \
	V3DHFLoadFromFile.3 \
	V3DIntro.3 \
	V3DLoadModel.3 \
	V3DMHCreate.3 \
	V3DMHDestroy.3 \
	V3DMHHeightfieldBaseDirectoryGet.3 \
	V3DMHHeightfieldBaseDirectorySet.3 \
	V3DMHListDelete.3 \
	V3DMHListDeleteAll.3 \
	V3DMHListGetPtr.3 \
	V3DMHListInsert.3 \
	V3DMHTextureBaseDirectoryGet.3 \
	V3DMHTextureBaseDirectorySet.3 \
	V3DMPCreate.3 \
	V3DMPDestroy.3 \
	V3DMPDup.3 \
	V3DMPFlipWinding.3 \
	V3DMPGetNormal.3 \
	V3DMPGetTexCoord.3 \
	V3DMPGetTotal.3 \
	V3DMPGetVertex.3 \
	V3DMPListGetPtr.3 \
	V3DMPListInsert.3 \
	V3DMPUnitlizeNormal.3 \
	V3DModelCreate.3 \
	V3DModelDestroy.3 \
	V3DModelDup.3 \
	V3DModelListDelete.3 \
	V3DModelListDeleteAll.3 \
	V3DModelListGetPtr.3 \
	V3DModelListInsert.3 \
	V3DSaveModel.3 \
	V3DTextureDestroy.3 \
	V3DTextureLoadFromData1D.3 \
	V3DTextureLoadFromData2D.3 \
	V3DTextureLoadFromFile2D.3 \
	V3DTextureLoadFromFile2DPreempt.3 \
	V3DTexturePriority.3 \
	V3DTextureSelect.3 \
	V3DTextureSelectFrame.3 \
	v3d_glinterprite_struct.3 \
	v3d_glresource_struct.3 \
	v3d_hf_options_struct.3 \
	v3d_texture_ref_struct.3

post-patch:
	@${REINPLACE_CMD} -e "s,make,${GMAKE},g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s,%%CFLAGS%%,${CFLAGS},g" \
		-e "s,%%X11BASE%%,${X11BASE},g" \
		-e "s,%%PTHREAD_CFLAGS%%,${PTHREAD_CFLAGS},g" \
		-e "s,%%PTHREAD_LIBS%%,${PTHREAD_LIBS},g" \
		${WRKSRC}/libv3d/platforms.ini

.include <bsd.port.mk>
