# New ports collection makefile for:	thot
# Version required:	2.1b
# Date created:		1 Aug 1997
# Whom:			Pedro Giffuni (orig)
#
# $Id: Makefile,v 1.3 1997/09/17 04:46:56 chuckr Exp $
#

DISTNAME=	Thot
PKGNAME=	thoteditor-2.1b
CATEGORIES=	editors www
MASTER_SITES=	ftp://ftp.uni-paderborn.de/ftp/disk6/unix/infosys/www/clients/amaya/thot/ \
		ftp://ftp.ruhr-uni-bochum.de/local/jk.collection/thot/ \
		ftp://ftp.cs.itu.edu.tr/pub/Linux/Apps/Editors/ \
		ftp://ftp.uni-stuttgart.de/pub/comm/infosystems/www/clients/amaya/thot/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/editors/opera.inrialpes.fr/sources/thot/ \
		ftp://ftp.agix.net/pub/infosystems/www/clients/amaya/thot/ \
		ftp://ftp.cnti.chel.su/pub/linux/X11/apps/thot/
DISTFILES=	thot-src-2.1b.tar.gz		\
		thoteditor-src-2.1b.tar.gz

MAINTAINER=	ports@FreeBSD.org

EXTRACT_ONLY=	thot-src-2.1b.tar.gz
REQUIRES_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-thot --enable-plugin
USE_GMAKE=	yes
ALL_TARGET=	all schemas

post-extract:
	($(EXTRACT_CMD) $(EXTRACT_BEFORE_ARGS) $(DISTDIR)/thoteditor-src-2.1b.tar.gz -C $(WRKSRC))

post-install:
	${MKDIR} ${PREFIX}/share/thot/doc

.include <bsd.port.mk>
