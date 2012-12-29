# Created by: pgf
# $FreeBSD$

PORTNAME=	vile
PORTVERSION=	9.8g
CATEGORIES=	editors
MASTER_SITES=	ftp://dickey.his.com/vile/current/ \
		ftp://invisible-island.net/vile/current/ \
		ftp://ftp.phred.org/pub/vile/current/
DISTNAME=	vile-9.8g
EXTRACT_SUFX=	.tgz

PATCH_SITES=	${MASTER_SITES:S,vile/current/,vile/patches/,g}
PATCHFILES=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VI Like Emacs.  a vi "workalike", with many additional features

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
MAN1=		vile.1
MAKE_JOBS_SAFE=	yes

OPTIONS= FILTERS "Add support for loadable filters" OFF
OPTIONS+= ICONV "Add support for ICONV" OFF
OPTIONS+= PERL "Add support for perl functions" OFF

.include <bsd.port.pre.mk>

.if defined(WITH_ICONV)
CONFIGURE_ARGS+=	--with-iconv
USE_ICONV=	yes
.else
CONFIGURE_ARGS+=	--without-iconv
CONFIGURE_ARGS+=	--without-locale
.endif

.if defined(WITH_PERL)
CONFIGURE_ARGS+=	--with-perl
PLIST=		${PKGDIR}/pkg-plist.perl
USE_PERL5=	yes
.endif

.if defined(WITH_FILTERS)
CONFIGURE_ARGS+=	--with-loadable-filters
PLIST=		${PKGDIR}/pkg-plist.filt
.endif

.if defined(WITH_PERL) && defined(WITH_FILTERS)
PLIST=		${PKGDIR}/pkg-plist.perl+filt
.endif

pre-configure:
.if !defined(WITH_ICONV)
	@${ECHO_MSG} "Choose the option ICONV if you want to make a vile which includes"
	@${ECHO_MSG} "ICONV functionality"
.endif
.if !defined(WITH_PERL)
	@${ECHO_MSG} "Choose the option PERL if you want to make a vile which includes"
	@${ECHO_MSG} "PERL functionality"
.endif
.if !defined(WITH_FILTERS)
	@${ECHO_MSG} "Choose the option FILTERS if you want to make a vile which will"
	@${ECHO_MSG} "dynamically load filters as needed."
.endif

post-install:
.if !defined(NOPORTDOCS)
	@if ! [ -d ${PREFIX}/share/doc/vile ]; then ${MKDIR} ${PREFIX}/share/doc/vile; fi
	${INSTALL_DATA} ${WRKSRC}/doc/*.doc ${PREFIX}/share/doc/vile
.endif
	@if ! [ -d ${PREFIX}/share/vile/macros ]; then ${MKDIR} ${PREFIX}/share/vile/macros; fi
	${INSTALL_DATA} ${WRKSRC}/macros/*.rc ${PREFIX}/share/vile/macros
	${INSTALL_SCRIPT} ${WRKSRC}/macros/vile-pager ${PREFIX}/share/vile/macros
	@${ECHO_MSG} "Look in ${PREFIX}/share/doc/vile for documentation."
	@${ECHO_MSG} "Look in ${PREFIX}/share/vile/macros for macros."

.include <bsd.port.post.mk>
