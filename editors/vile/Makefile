# Created by: pgf
# $FreeBSD$

PORTNAME=	vile
PORTVERSION=	9.8l
CATEGORIES=	editors
MASTER_SITES=	ftp://dickey.his.com/vile/current/ \
		ftp://invisible-island.net/vile/current/
EXTRACT_SUFX=	.tgz

PATCH_SITES=	${MASTER_SITES:S,vile/current/,vile/patches/,g}
PATCHFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VI Like Emacs -- console version

LICENSE=	GPLv2

BUILD_DEPENDS=	reflex:${PORTSDIR}/textproc/reflex

USES=		pkgconfig shebangfix
SHEBANG_FILES=	perl/vileget
GNU_CONFIGURE=	yes
MAKEFILE=	makefile

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
		's|^DOCDIR|#DOCDIR|' ${WRKSRC}/makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/macros
	(cd ${WRKSRC}/macros && ${INSTALL_DATA} *.rc \
		${STAGEDIR}${DATADIR}/macros)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.doc \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
