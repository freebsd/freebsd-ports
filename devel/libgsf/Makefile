PORTNAME=	libgsf
DISTVERSION=	1.14.58
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Structured file library from GNOME
WWW=		https://gitlab.gnome.org/GNOME/libgsf/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	zipinfo:archivers/unzip \
		p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		cpe gmake gnome libtool localbase pathfix perl5 pkgconfig \
		shebangfix tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	gdkpixbuf glib20 libxml2 introspection:build
USE_PERL5=	test
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-introspection

INSTALL_TARGET=	install-strip
TEST_TARGET=	check
SHEBANG_FILES=	tests/*.pl

PLIST_SUB+=	LIBMINORVER=${DISTVERSION:E} \
		LIBSHORTVER=${DISTVERSION:R:S/.//}

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
