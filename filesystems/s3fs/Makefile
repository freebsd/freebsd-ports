PORTNAME=	s3fs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.95
PORTREVISION=	1
CATEGORIES=	filesystems
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FUSE-based file system backed by Amazon S3
WWW=		https://github.com/s3fs-fuse/s3fs-fuse

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		autoreconf fuse gnome pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	s3fs-fuse
GH_PROJECT=	s3fs-fuse
USE_GNOME=	libxml2

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	ac_cv_prog_GITCMD=no

PLIST_FILES=	bin/s3fs share/man/man1/s3fs.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's/libcrypto >= 0.9//' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e '/DEPS_LIBS/s/$$/ -lcrypto/' \
		${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
