PORTNAME=	gobby
DISTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://releases.0x539.de/gobby/

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Free collaborative editor
WWW=		http://gobby.0x539.de

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libgsasl.so:security/libgsasl \
		libinfgtk-0.7.so:textproc/libinfinity \
		libinfinity-0.7.so:textproc/libinfinity \
		libinftext-0.7.so:textproc/libinfinity \
		libinftextgtk-0.7.so:textproc/libinfinity

USES=		compiler:c++11-lang desktop-file-utils gettext-tools gmake \
		gnome pathfix pkgconfig
USE_CXXSTD=	c++11
USE_GNOME=	atkmm cairomm glibmm gtkmm30 gtksourceview3 intltool \
		libsigc++20 libxml++26 pangomm

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls

post-install:
	@cd ${STAGEDIR}${PREFIX}/bin && \
		${MV} gobby-0.5 \
		gobby
	@cd ${STAGEDIR}${PREFIX}/share/man/man1 && \
		${MV} gobby-0.5.1 \
		gobby.1

.include <bsd.port.mk>
