PORTNAME=	kasumi-unicode
DISTVERSION=	2.7
CATEGORIES=	japanese
MASTER_SITES=	https://github.com/fujiwarat/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Dictionary management tool for anthy-unicode
WWW=		https://github.com/fujiwarat/kasumi-unicode/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libanthy-unicode.so:japanese/anthy-unicode

USES=		autoreconf compiler:c++14-lang gmake gnome iconv:wchar_t \
		libtool pkgconfig
USE_CXXSTD=	c++14
USE_GNOME=	gtk30

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
