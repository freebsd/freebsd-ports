# ex:ts=8
# New ports collection makefile for:	libcomprex
# Date created:			Nov 22, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libcomprex
PORTVERSION=	0.3.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnupdate

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl
.if !exists(/usr/bin/bzip2) 
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_LIBTOOL=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

MAN1=	comprex-config.1
MAN3=	cxCleanup.3 cxCleanupModules.3 cxClearErr.3 cxClose.3 \
	cxCloseArchive.3 cxCloseFile.3 cxDestroyArchive.3 \
	cxDestroyDirectory.3 cxDestroyFile.3 cxDirAddFile.3 \
	cxDirAddSubDir.3 cxDirRemoveFile.3 cxDirRemoveSubDir.3 cxEof.3 \
	cxError.3 cxFixPath.3 cxGetArchiveAccessMode.3 cxGetArchiveFileName.3 \
	cxGetArchiveFileSize.3 cxGetArchiveModule.3 cxGetArchivePath.3 \
	cxGetArchivePhysicalPath.3 cxGetArchiveRoot.3 cxGetArchiveSize.3 \
	cxGetArchiveType.3 cxGetBaseName.3 cxGetBasePath.3 cxGetDirArchive.3 \
	cxGetDirParent.3 cxGetDirectory.3 cxGetDirectoryName.3 cxGetFile.3 \
	cxGetFileArchive.3 cxGetFileCompressedSize.3 cxGetFileCount.3 \
	cxGetFileDate.3 cxGetFileGid.3 cxGetFileMode.3 cxGetFileName.3 \
	cxGetFileParent.3 cxGetFilePath.3 cxGetFilePhysicalPath.3 \
	cxGetFileSize.3 cxGetFileType.3 cxGetFileUid.3 cxGetFirstFile.3 \
	cxGetFirstModule.3 cxGetFirstSubDir.3 cxGetFpAccessMode.3 \
	cxGetFullFilePath.3 cxGetModule.3 cxGetNextDir.3 cxGetNextFile.3 \
	cxGetPreviousDir.3 cxGetPreviousFile.3 cxGetSubDirCount.3 \
	cxIsArchiveLocal.3 cxIsFileLocal.3 cxLinkModule.3 cxLoadModule.3 \
	cxNewArchive.3 cxNewDirectory.3 cxNewFile.3 cxNewFp.3 cxOpenArchive.3 \
	cxOpenArchiveBuffer.3 cxOpenArchiveStream.3 cxOpenBuffer.3 \
	cxOpenFile.3 cxOpenFileHandle.3 cxOpenStream.3 cxRead.3 \
	cxRegisterModule.3 cxRewind.3 cxSaveArchive.3 cxSeek.3 \
	cxSetArchiveAccessMode.3 cxSetArchiveFileName.3 \
	cxSetArchiveFileSize.3 cxSetArchiveLocal.3 cxSetArchiveModule.3 \
	cxSetArchivePath.3 cxSetArchivePhysicalPath.3 cxSetArchiveSize.3 \
	cxSetArchiveType.3 cxSetCloseFunc.3 cxSetDirArchive.3 \
	cxSetDirParent.3 cxSetDirectoryName.3 cxSetError.3 cxSetFileArchive.3 \
	cxSetFileCompressedSize.3 cxSetFileDate.3 cxSetFileGid.3 \
	cxSetFileLocal.3 cxSetFileMode.3 cxSetFileName.3 cxSetFileParent.3 \
	cxSetFilePath.3 cxSetFilePhysicalPath.3 cxSetFileSize.3 \
	cxSetFileType.3 cxSetFileUid.3 cxSetFpAccessMode.3 cxSetReadFunc.3 \
	cxSetSeekFunc.3 cxSetWriteFunc.3 cxStrError.3 cxTell.3 \
	cxUnlinkModule.3 cxUnloadModule.3 cxWrite.3

.include <bsd.port.mk>
