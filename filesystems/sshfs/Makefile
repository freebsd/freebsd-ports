PORTNAME=	sshfs
DISTVERSION=	3.7.7
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	filesystems
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Mount remote directories over ssh
WWW=		https://github.com/libfuse/sshfs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 fuse:3 gnome meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	libfuse
USE_GNOME=	glib20

CFLAGS+=	-DNDEBUG

PLIST_FILES=	bin/sshfs

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	rst2man:textproc/py-docutils
DOCS_PLIST_FILES=	share/man/man1/sshfs.1.gz

.include <bsd.port.mk>
