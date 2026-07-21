PORTNAME=	curlftpfs
PORTVERSION=	0.9.2
PORTREVISION=	9
CATEGORIES=	filesystems
MASTER_SITES=	SF
PKGNAMEPREFIX=	fusefs-
DIST_SUBDIR=	${PORTNAME}

PATCH_SITES=	https://sources.debian.org/data/main/c/curlftpfs/0.9.2-9/debian/patches/ \
		https://sourceforge.net/p/curlftpfs/patches/_discuss/thread/bb0c32f92b/5e56/attachment/:krblevel
PATCHFILES=	fix-CURLOPT_INFILESIZE.patch \
		free_ftpfs_file-memleak-fix.patch \
		getpass-prototype.patch \
		nocache-memleak-fix.patch \
		curlftpfs__no_verify_hostname.patch \
		consistent-feature-flag.patch \
		curlftpfs.patch:krblevel
PATCH_DIST_STRIP=	-p1

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Mount remote FTP directories
WWW=		https://curlftpfs.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		fuse gnome pkgconfig
USE_GNOME=	glib20

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/curlftpfs \
		share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
