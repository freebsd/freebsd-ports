# New ports collection makefile for:	thot
# Version required:	2.1b
# Date created:		1 Aug 1997
# Whom:			Pedro Giffuni (orig)
#
# $Id:
#

DISTNAME=	Thot
PKGNAME=	thoteditor-2.1b
CATEGORIES=	editors www
MASTER_SITES=	ftp://opera.inrialpes.fr/pub/sources/thot/
DISTFILES=	thot-src-2.1b.tar.gz		\
		thoteditor-src-2.1b.tar.gz
EXTRACT_ONLY=	thot-src-2.1b.tar.gz

MAINTAINER=	ports@FreeBSD.org

REQUIRES_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-thot --enable-plugin
USE_GMAKE=	yes
ALL_TARGET=	all schemas

post-extract:
	($(EXTRACT_CMD) $(EXTRACT_BEFORE_ARGS) $(DISTDIR)/thoteditor-src-2.1b.tar.gz -C $(WRKSRC))

.include <bsd.port.mk>
