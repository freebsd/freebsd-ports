# New ports collection makefile for:	thot
# Date created:		1 Aug 1997
# Whom:			Pedro Giffuni (orig)
#
# $FreeBSD$
#

PORTNAME=	thoteditor
PORTVERSION=	2.1e
PORTREVISION=	1
CATEGORIES=	editors www
MASTER_SITES=	ftp://ftp.inrialpes.fr/pub/opera/sources/thot/ \
		ftp://ftp.ruhr-uni-bochum.de/local/jk.collection/thot/
MASTER_SITE_SUBDIR=	apps/editors/X/thot
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An structured document editor, offering a graphical WYSIWYG interface

.include <bsd.port.pre.mk>

THOT_SUBDIR=	Target
USE_MOTIF=	yes
WRKSRC=		$(WRKDIR)/Thot/$(THOT_SUBDIR)
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-thot --enable-plugin --without-insure --without-amaya --disable-java --disable-intr --disable-jit --disable-math --disable-ilu
USE_GMAKE=	yes
ALL_TARGET=	all schemas
MAN1=		cextract.1
MAN5=		cextrc.5

do-configure:
	$(CP) $(WRKSRC)/../thot/Makefile.in $(WRKSRC)/../thot/Makefile.in.patched
	$(SED) -e "s&%%MOTIFLIB%%&$(MOTIFLIB)&" <$(WRKSRC)/../thot/Makefile.in.patched >$(WRKSRC)/../thot/Makefile.in
	(cd $(WRKSRC);../configure $(CONFIGURE_ARGS))

post-configure:
	$(CP) $(WRKSRC)/../thotlib/base/registry.c $(WRKSRC)/../thotlib/base/registry.c.orig
	$(SED) -e "s&%%PREFIX%%&$(PREFIX)&" <$(WRKSRC)/../thotlib/base/registry.c.orig >$(WRKSRC)/../thotlib/base/registry.c

post-extract:
	(cd $(WRKDIR)/Thot;$(MKDIR) $(THOT_SUBDIR))

post-install:
	${MKDIR} ${PREFIX}/share/thot/doc
	$(SED) -e "s&%%PREFIX%%&$(PREFIX)&" < $(FILESDIR)/thoteditor > $(WRKDIR)/thoteditor
	$(INSTALL_SCRIPT) $(WRKDIR)/thoteditor $(PREFIX)/bin
	$(INSTALL_MAN) $(WRKSRC)/../tools/cextract-1.7/cextrc.5 $(PREFIX)/man/man5
	$(INSTALL_MAN) $(WRKSRC)/../tools/cextract-1.7/cextract.man $(PREFIX)/man/man1/cextract.1

.include <bsd.port.post.mk>
