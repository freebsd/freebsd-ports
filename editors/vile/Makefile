# Created by: pgf
# $FreeBSD$

PORTNAME=	vile
PORTVERSION=	9.8g
CATEGORIES=	editors
MASTER_SITES=	ftp://dickey.his.com/vile/current/ \
		ftp://invisible-island.net/vile/current/ \
		ftp://ftp.phred.org/pub/vile/current/
EXTRACT_SUFX=	.tgz

PATCH_SITES=	${MASTER_SITES:S,vile/current/,vile/patches/,g}
PATCHFILES=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VI Like Emacs.  a vi "workalike", with many additional features

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
MAN1=		vile.1
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	FILTERS ICONV PERL DOCS
FILTERS_DESC=	Loadable filters

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MICONV}
CONFIGURE_ARGS+=	--with-iconv
USE_ICONV=	yes
.else
CONFIGURE_ARGS+=	--without-iconv
CONFIGURE_ARGS+=	--without-locale
.endif

.if ${PORT_OPTIONS:MPERL}
CONFIGURE_ARGS+=	--with-perl
PLIST=		${PKGDIR}/pkg-plist.perl
USE_PERL5=	yes
.endif

.if ${PORT_OPTIONS:MFILTERS}
CONFIGURE_ARGS+=	--with-loadable-filters
PLIST=		${PKGDIR}/pkg-plist.filt
.endif

.if ${PORT_OPTIONS:MPERL} && ${PORT_OPTIONS:MFILTERS}
PLIST=		${PKGDIR}/pkg-plist.perl+filt
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@if ! [ -d ${PREFIX}/share/doc/vile ]; then ${MKDIR} ${PREFIX}/share/doc/vile; fi
	${INSTALL_DATA} ${WRKSRC}/doc/*.doc ${PREFIX}/share/doc/vile
.endif
	@if ! [ -d ${PREFIX}/share/vile/macros ]; then ${MKDIR} ${PREFIX}/share/vile/macros; fi
	${INSTALL_DATA} ${WRKSRC}/macros/*.rc ${PREFIX}/share/vile/macros
	${INSTALL_SCRIPT} ${WRKSRC}/macros/vile-pager ${PREFIX}/share/vile/macros
	@${ECHO_MSG} "Look in ${PREFIX}/share/doc/vile for documentation."
	@${ECHO_MSG} "Look in ${PREFIX}/share/vile/macros for macros."

.include <bsd.port.mk>
