PORTNAME=	qof
PORTVERSION=	0.8.8
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	qof_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Query Object Framework
WWW=		https://alioth.debian.org/projects/qof/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Host is no longer resolvable using multiple different resolver
EXPIRATION_DATE=	2025-08-23

CONFLICTS_INSTALL=	gnotime-2.[0-3]* gnotime-2.4.0* gnotime-2.4.1 gnotime-2.4.1_[12]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doxygen --disable-gdasql --disable-sqlite
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		gmake gnome libtool pkgconfig
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e '/CFLAGS=/s|-g2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|__isleap|qof_date_isleap|' \
		${WRKSRC}/qof/qofdate.c
	@${REINPLACE_CMD} -e '/^AM_CFLAGS =/s|-g||' \
		${WRKSRC}/lib/libsql/Makefile.in \
		${WRKSRC}/qof/Makefile.in
	@${REINPLACE_CMD} -e '/^sql_parse_test_DEPENDENCIES =/s/$$/ libqofsql.la/' \
		${WRKSRC}/lib/libsql/Makefile.in

.include <bsd.port.mk>
