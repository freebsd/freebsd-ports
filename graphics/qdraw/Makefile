# New ports collection makefile for:	QDraw
# Date created:		1 Aug 2001
# Whom:			Nick Hibma <n_hibma@qubesoft.com>
#
# $FreeBSD$
#

PORTNAME=	QDraw
PORTVERSION=	0.7
CATEGORIES=	graphics
MASTER_SITES=	http://qdn.qubesoft.com/QDraw/download/
DISTNAME=	${PKGNAME}

MAINTAINER=	n_hibma@FreeBSD.org

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		GL:${PORTSDIR}/graphics/Mesa3
.if defined(AALIB)
LIB_DEPENDS+=	aa:${PORTSDIR}/graphics/aalib
.endif

INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
ONLY_FOR_ARCHS=	i386
# GCC 2.95 or later
USE_NEWGCC=	yes

MAKEFILE=	makefile

# The all target is 'install' not 'all', due to the layering of
# libraries (which have to be installed in a final dir before
# layers above that can be built.
ALL_TARGET=	includes install

# The install target is 'install' with a different prefix.
INSTALL_TARGET=	PREFIX=${PREFIX} SAMPLESDIR=share/examples/qdraw install

# We are not using a standard ./configure script but a handwritten one.
do-configure:
	cd ${WRKSRC} && ./configure --defaults

.if !defined(AALIB)
pre-configure:
	@echo "You can link against libaa (ASCII art OpenGL renderer) by"
	@echo "adding 'AALIB=1' to the make command line."
.endif

.include <bsd.port.mk>
