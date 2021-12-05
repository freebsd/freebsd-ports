# Created by: Anders Nordby <anders@fix.no>

PORTNAME=	mdbtools
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Utilities and libraries to export data from MS Access databases (.mdb)

LICENSE=	GPLv2

BUILD_DEPENDS=	bash-completion>=0:shells/bash-completion \
		flex:textproc/flex \
		gawk:lang/gawk
LIB_DEPENDS=	libodbcinst.so:databases/unixODBC
RUN_DEPENDS=	bash-completion>=0:shells/bash-completion

USES=		autoreconf bison gnome iconv:wchar_t libtool pathfix \
		pkgconfig readline
USE_GITHUB=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--with-unixodbc=${LOCALBASE}

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${WRKSRC}/include

OPTIONS_DEFINE=		DOCS MANPAGES LIBMSWSTR NLS
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

LIBMSWSTR_DESC=	Read and parse JET 4 mdb file indices

LIBMSWSTR_LIB_DEPENDS=		libmswstr.so:databases/libmswstr
LIBMSWSTR_CONFIGURE_ENV_OFF=	ac_cv_lib_mswstr_DBLCMapStringW=no
MANPAGES_CONFIGURE_OFF=		--disable-man
NLS_USES=			gettext

DOCS=		AUTHORS HACKING.md NEWS README.md TODO.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,}  ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
