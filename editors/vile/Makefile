# New ports collection makefile for:    vile
# Date created:         Wed Nov 26, 1996
# Whom:                 pgf
#
# $FreeBSD$
#

PORTNAME=	vile
PORTVERSION=	9.2t
DISTNAME=	vile-9.2
CATEGORIES=	editors
MASTER_SITES=   ftp://ftp.phred.org/pub/vile/ \
		ftp://dickey.his.com/vile/
PATCH_SITES=	${MASTER_SITES:S,vile/,vile/patches/,g}
PATCHFILES=	vile-9.2a.patch.gz \
		vile-9.2b.patch.gz \
		vile-9.2c.patch.gz \
		vile-9.2d.patch.gz \
		vile-9.2e.patch.gz \
		vile-9.2f.patch.gz \
		vile-9.2g.patch.gz \
		vile-9.2h.patch.gz \
		vile-9.2i.patch.gz \
		vile-9.2j.patch.gz \
		vile-9.2k.patch.gz \
		vile-9.2l.patch.gz \
		vile-9.2m.patch.gz \
		vile-9.2n.patch.gz \
		vile-9.2o.patch.gz \
		vile-9.2p.patch.gz \
		vile-9.2q.patch.gz \
		vile-9.2r.patch.gz \
		vile-9.2s.patch.gz \
		vile-9.2t.patch.gz

EXTRACT_SUFX=	.tgz

MAINTAINER=	gj@freebsd.org

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
MAN1=		vile.1

.if defined(WITH_PERL)
CONFIGURE_ARGS=	--with-perl
PLIST=		${PKGDIR}/pkg-plist.perl
USE_PERL5=	yes
.endif

.if defined(WITH_FILTERS)
CONFIGURE_ARGS+= --with-builtin-filters=all
PLIST=		${PKGDIR}/pkg-plist.filt
.endif

.if defined(WITH_PERL) && defined(WITH_FILTERS)
PLIST=		${PKGDIR}/pkg-plist.perl+filt
.endif

pre-configure:
.if ! defined(WITH_PERL)
	@${ECHO_MSG} "Define WITH_PERL if you want to make a vile which includes"
	@${ECHO_MSG} "PERL functionality"
.endif
.if ! defined(WITH_FILTERS)
	@${ECHO_MSG} "Define WITH_FILTERS if you want to make a vile which includes"
	@${ECHO_MSG} "all filters in the binary"
.endif

post-install:
.if !defined(NOPORTDOCS)
	@if ! [ -d ${PREFIX}/share/doc/vile ]; then ${MKDIR} ${PREFIX}/share/doc/vile; fi
	${INSTALL_DATA} ${WRKSRC}/doc/*.doc ${PREFIX}/share/doc/vile
.endif
	@if ! [ -d ${PREFIX}/share/vile/macros ]; then ${MKDIR} ${PREFIX}/share/vile/macros; fi
	${INSTALL_DATA} ${WRKSRC}/macros/*.rc ${PREFIX}/share/vile/macros
	${INSTALL_SCRIPT} ${WRKSRC}/macros/vile-pager ${PREFIX}/share/vile/macros
.if defined(WITH_PERL)
	${INSTALL_DATA} ${WRKSRC}/*.doc ${PREFIX}/share/doc/vile
.endif
	@${ECHO_MSG} "Look in ${PREFIX}/share/doc/vile for documentation."
	@${ECHO_MSG} "Look in ${PREFIX}/share/vile/macros for macros."

.include <bsd.port.mk>
