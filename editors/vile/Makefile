# Created by: pgf
# $FreeBSD$

PORTNAME=	vile
PORTVERSION=	9.8t
CATEGORIES=	editors
MASTER_SITES=	ftp://dickey.his.com/vile/current/ \
		ftp://ftp.invisible-island.net/vile/current/ \
		https://invisible-mirror.net/archives/vile/current/

PATCH_SITES=	${MASTER_SITES:S,vile/current/,vile/patches/,g}
#PATCHFILES=

MAINTAINER=	dickey@invisible-island.net
COMMENT=	VI Like Emacs -- console version

LICENSE=	GPLv2

BUILD_DEPENDS=	reflex:textproc/reflex

USES=		ncurses pkgconfig shebangfix tar:tgz
SHEBANG_FILES=	perl/vileget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	cf_cv_crypt_works=yes
MAKEFILE=	makefile
INSTALL_TARGET=	install install-doc install-html

CONFLICTS_INSTALL=	xvile-[0-9]*

OPTIONS_DEFINE=		DOCS FILTERS ICONV PERL
OPTIONS_SUB=		yes

FILTERS_DESC=		Loadable filters
FILTERS_CONFIGURE_WITH=	loadable-filters
ICONV_USES=		iconv
ICONV_CONFIGURE_ON=	--with-iconv ${ICONV_CONFIGURE_ARG}
ICONV_CONFIGURE_OFF=	--without-iconv --without-locale
PERL_USES=		perl5
PERL_CONFIGURE_WITH=	perl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFILTERS}
PLIST_SUB+=	SO_EXT=".so"
.else
PLIST_SUB+=	SO_EXT=""
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(datadir)/doc|@datadir@/doc/vile| ; \
		 s|$$(datadir)/html|$$(docdir)/html| ; \
		 s|\($$(DOCDIR)\) \($$(MANDIR)\)|\1 $$(HTMLDIR) \2|' \
		${WRKSRC}/makefile.in

.include <bsd.port.mk>
