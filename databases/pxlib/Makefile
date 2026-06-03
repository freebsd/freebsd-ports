PORTNAME=	pxlib
DISTVERSION=	0.6.10
CATEGORIES=	databases

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	C library to read various Paradox files
WWW=		https://github.com/steinm/pxlib/

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		autoreconf gmake gnome iconv libtool localbase:ldflags perl5 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	steinm
GH_TAGNAME=		R-${DISTVERSION:S/./-/g}
USE_GNOME=	intltool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PLIST_SUB=		SOVERSION=0.6.9

OPTIONS_DEFINE=	MANPAGES NLS
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	docbook-to-man:textproc/docbook-to-man \
			docbook2man:textproc/docbook-utils
NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

pre-build-MANPAGES-off:
	${REINPLACE_CMD} -e 's/^DOCDIR =.*/DOCDIR =/' ${WRKSRC}/Makefile

.include <bsd.port.mk>
