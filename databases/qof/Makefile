PORTNAME=	qof
DISTVERSION=	g20250913
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	databases

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Query Object Framework
WWW=		https://github.com/GnoTime/qof

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doxygen --disable-sqlite
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		autoreconf gmake gnome libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	GnoTime
GH_PROJECT=	qof
GH_TAGNAME=	f4b5d111a91af1e5606bd1db74c4db454ae77124
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e '/CFLAGS=/s|-g2||' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|__isleap|qof_date_isleap|' \
		${WRKSRC}/qof/qofdate.c
	@${REINPLACE_CMD} -e '/^AM_CFLAGS =/s|-g||' \
		${WRKSRC}/lib/libsql/Makefile.am \
		${WRKSRC}/qof/Makefile.am
	@${REINPLACE_CMD} -e '/^sql_parse_test_DEPENDENCIES =/s/$$/ libqofsql.la/' \
		${WRKSRC}/lib/libsql/Makefile.am

.include <bsd.port.mk>
