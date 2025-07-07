PORTNAME=	dsbmd
PORTVERSION=	1.12
CATEGORIES=	filesystems sysutils

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Media mounting daemon
WWW=		https://github.com/mrclksr/DSBMD

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:tgz
USE_GITHUB=	yes
GH_ACCOUNT=	mrclksr
GH_PROJECT=	DSBMD
USE_RC_SUBR=	dsbmd

PLIST_FILES=	"@sample etc/dsbmd.conf.sample" \
		libexec/dsbmd

PORTDOCS=	readme.mdoc

OPTIONS_DEFINE=		DOCS EXFAT EXT4 HFS LKL MTP NTFS PTP
OPTIONS_DEFAULT=	EXT4 MTP NTFS PTP

EXFAT_DESC=	exFAT filesystem support
EXT4_DESC=	Ext4 filesystem support
HFS_DESC=	HFS+ support
LKL_DESC=	Btrfs and XFS support through Linux Kernel Library
NTFS_DESC=	Mount NTFS filesystems with read and write support
PTP_DESC=	Picture Transfer Protocol support

EXFAT_RUN_DEPENDS=	mount.exfat:filesystems/exfat
EXT4_RUN_DEPENDS=	fuse-ext2:filesystems/ext2
HFS_RUN_DEPENDS=	hfsfuse:filesystems/hfsfuse
LKL_RUN_DEPENDS=	lklfuse:filesystems/lkl
MTP_RUN_DEPENDS=	jmtpfs:filesystems/jmtpfs
NTFS_RUN_DEPENDS=	ntfs-3g:filesystems/ntfs
PTP_RUN_DEPENDS=	gphotofs:filesystems/gphotofs

.include <bsd.port.mk>
