PORTNAME=	curlftpfs
PORTVERSION=	0.9.2
PORTREVISION=	8
CATEGORIES=	filesystems
MASTER_SITES=	SF
PKGNAMEPREFIX=	fusefs-
DIST_SUBDIR=	${PORTNAME}

PATCH_SITES=	https://sources.debian.org/data/main/c/curlftpfs/0.9.2-9/debian/patches/
PATCHFILES=	fix-CURLOPT_INFILESIZE.patch \
		free_ftpfs_file-memleak-fix.patch \
		nocache-memleak-fix.patch \
		curlftpfs__no_verify_hostname.patch \
		consistent-feature-flag.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Mount remote FTP directories
WWW=		https://curlftpfs.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		fuse gnome pkgconfig
USE_GNOME=	glib20

GNU_CONFIGURE=			yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/curlftpfs \
		share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
