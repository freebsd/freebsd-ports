# New ports collection makefile for:	frei0r
# Date created:		17 November 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	frei0r
PORTVERSION=	1.3
DISTVERSIONPREFIX=	plugins-
CATEGORIES=	graphics
MASTER_SITES=	http://piksel.no/${PORTNAME}/releases/ \
		ftp://ftp.dyne.org/${PORTNAME}/releases/ \
		http://distfiles.macports.org/${PORTNAME}-plugins/

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Minimalistic plugin API for video effects

LIB_DEPENDS=	cv.2:${PORTSDIR}/graphics/opencv \
		gavl.1:${PORTSDIR}/multimedia/gavl

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
MAKE_JOBS_SAFE=	yes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PORTDOCS=	*

OPTIONS=	APIDOC "Install full documentation (requires doxygen)" off \
		MMX "Enable MMX CPU instructions" off

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.options.mk>

.if !defined(NOPORTDOCS) && defined(WITH_APIDOC)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.endif

.if !defined(WITH_MMX)
CONFIGURE_ARGS+=--disable-cpuflags
.endif

post-patch:
.if !defined(NOPORTDOCS) && defined(WITH_APIDOC)
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|include|include doc|' ${WRKSRC}/Makefile.in
.endif
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e '/^install-data-am/s| install-docsDATA||' \
		${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|^docsdir.*|docsdir = ${DOCSDIR}|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|^htmldocsdir.*|htmldocsdir = ${DOCSDIR}|' \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
