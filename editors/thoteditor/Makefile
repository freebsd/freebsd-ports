# New ports collection makefile for:	thot
# Version required:	2.1e
# Date created:		1 Aug 1997
# Whom:			Pedro Giffuni (orig)
#
# $FreeBSD$
#

DISTNAME=	thoteditor
PKGNAME=	thoteditor-2.1e
CATEGORIES=	editors www
MASTER_SITES=	ftp://ftp.inrialpes.fr/pub/opera/sources/thot/ \
		${MASTER_SITE_SUNSITE} \
		ftp://ftp.ruhr-uni-bochum.de/local/jk.collection/thot/ \
		ftp://ftp.uni-stuttgart.de/pub/comm/infosystems/www/clients/amaya/thot/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/editors/opera.inrialpes.fr/sources/thot/ \
		ftp://ftp.agix.net/pub/infosystems/www/clients/amaya/thot/
MASTER_SITE_SUBDIR=	apps/editors/X/thot
DISTFILES=	${THOT_SRC} ${EDITOR_SRC}

MAINTAINER=	chuckr@FreeBSD.org

BROKEN= 'FUBARed'

THOT_SRC=	thot-src-2.1e.tar.gz
EDITOR_SRC=	thoteditor-src-2.1e.tar.gz

EXTRACT_ONLY=	${THOT_SRC}
REQUIRES_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-thot --enable-plugin
USE_GMAKE=	yes
ALL_TARGET=	all schemas

post-extract:
	(${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${EDITOR_SRC} ${EXTRACT_AFTER_ARGS} -C ${WRKSRC})

post-install:
	${MKDIR} ${PREFIX}/share/thot/doc

.include <bsd.port.mk>
