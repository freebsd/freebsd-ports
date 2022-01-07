# Created by: Anders Nordby <anders@fix.no>

PORTNAME=	mdbtools
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Utilities and libraries to export data from MS Access databases (.mdb)

LICENSE=	GPLv2

BUILD_DEPENDS=	bash-completion>=0:shells/bash-completion \
		flex:textproc/flex \
		gawk:lang/gawk
LIB_DEPENDS=	libodbcinst.so:databases/unixODBC
RUN_DEPENDS=	bash-completion>=0:shells/bash-completion

USES=		bison gnome iconv:wchar_t libtool pathfix \
		pkgconfig readline
USE_GNOME=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} \
		--with-unixodbc=${LOCALBASE}

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		DOCS MANPAGES LIBMSWSTR NLS
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

LIBMSWSTR_DESC=	Read and parse JET 4 mdb file indices

LIBMSWSTR_LIB_DEPENDS=		libmswstr.so:databases/libmswstr
LIBMSWSTR_CONFIGURE_ENV_OFF=	ac_cv_lib_mswstr_DBLCMapStringW=no
MANPAGES_CONFIGURE_OFF=		--disable-man
NLS_USES=			gettext

DOCS=		AUTHORS HACKING.md NEWS README.md

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,}  ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
