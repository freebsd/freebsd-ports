# ex:ts=8
# New ports collection makefile for:	libt1
# Date created:			13, May, 1999
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	t1lib
PORTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.neuroinformatik.ruhr-uni-bochum.de/pub/software/t1lib/
MASTER_SITE_SUBDIR=	libs/graphics

MAINTAINER=	ijliao@FreeBSD.org

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.if !defined(WITHOUT_X)
USE_XLIB=	yes
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/T1-${PORTVERSION}

# DOCS depends on LaTeX and LaTeX-babel module
#.if defined(NOPORTDOCS)
ALL_TARGET=	without_doc
#.else
#BUILD_DEPEND+=	${LOCALBASE}/bin/latex:${PORTSDIR}/print/latex
#.endif

INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
