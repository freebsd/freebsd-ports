# Created by: pgf
# $FreeBSD$

PORTNAME=	vile
PORTVERSION=	9.8k
CATEGORIES=	editors
MASTER_SITES=	ftp://dickey.his.com/vile/current/ \
		ftp://invisible-island.net/vile/current/
EXTRACT_SUFX=	.tgz

PATCH_SITES=	${MASTER_SITES:S,vile/current/,vile/patches/,g}
PATCHFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VI Like Emacs -- console version

LICENSE=	GPLv2

OPTIONS_DEFINE=	FILTERS ICONV PERL DOCS
FILTERS_DESC=	Loadable filters

USES=		pkgconfig shebangfix
SHEBANG_FILES=	perl/vileget
GNU_CONFIGURE=	yes
MAKEFILE=	makefile
MAKE_JOBS_SAFE=	yes

MAN1=		vile.1

CONFLICTS_INSTALL=	xvile-[0-9]*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFILTERS}
CONFIGURE_ARGS+=	--with-loadable-filters
PLIST_SUB+=	SO_EXT=".so"
.else
PLIST_SUB+=	SO_EXT=""
.endif

.if ${PORT_OPTIONS:MICONV}
USES+=		iconv
CONFIGURE_ARGS+=	--with-iconv --with-libiconv-prefix=${LOCALBASE}
PLIST_SUB+=	ICONV=""
.else
CONFIGURE_ARGS+=	--without-iconv --without-locale
PLIST_SUB+=	ICONV="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=	yes
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=	PERL=""
.else
PLIST_SUB+=	PERL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^DOCDIR|#DOCDIR|' ${WRKSRC}/makefile.in
	@${REINPLACE_CMD} -e \
		's|defined(FLEX_BETA)|0|' ${WRKSRC}/filters/filters.h

post-install:
	@${MKDIR} ${DATADIR}/macros
	(cd ${WRKSRC}/macros && ${INSTALL_DATA} *.rc ${DATADIR}/macros)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.doc ${DOCSDIR})
.endif

.include <bsd.port.mk>
