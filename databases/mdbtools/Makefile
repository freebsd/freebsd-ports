PORTNAME=	mdbtools
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.3
CATEGORIES=	databases

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Utilities and libraries to export data from MS Access databases (.mdb)

LICENSE=	GPLv2

BUILD_DEPENDS=	bash-completion>=0:shells/bash-completion \
		flex:textproc/flex \
		gawk:lang/gawk \
		txt2man:textproc/txt2man
LIB_DEPENDS=	libodbcinst.so:databases/unixODBC
RUN_DEPENDS=	bash-completion>=0:shells/bash-completion

USES=		autoreconf bison gettext gnome iconv libtool pathfix \
		pkgconfig readline
USE_GITHUB=	yes
GH_ACCOUNT=	mdbtools
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--with-unixodbc=${LOCALBASE}

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${WRKSRC}/include

OPTIONS_DEFINE=		DOCS MANPAGES LIBMSWSTR
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

LIBMSWSTR_DESC=	Read and parse JET 4 mdb file indices

LIBMSWSTR_LIB_DEPENDS=	libmswstr.so:databases/libmswstr
LIBMSWSTR_CONFIGURE_ENV_OFF=	ac_cv_lib_mswstr_DBLCMapStringW=no
MANPAGES_CONFIGURE_OFF=		--disable-man

DOCS=		AUTHORS ChangeLog HACKING NEWS README TODO.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,}  ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
