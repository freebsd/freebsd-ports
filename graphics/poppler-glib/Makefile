# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/graphics/poppler-glib/Makefile,v 1.4 2012/10/14 23:04:21 kwm Exp $

PORTREVISION=	0
PKGNAMESUFFIX=	-glib

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Glib bindings to poppler

MASTERDIR=	${.CURDIR}/../../graphics/poppler
SLAVEPORT=	glib
PLIST=	${.CURDIR}/pkg-plist
MAKE_ENV+=	GI_SCANNER_DISABLE_CACHE=yes

pre-build:
	@cd ${WRKSRC}/poppler && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} libpoppler-cairo.la

.include "${MASTERDIR}/Makefile"
