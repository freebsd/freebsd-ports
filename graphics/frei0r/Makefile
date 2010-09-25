# New ports collection makefile for:	frei0r
# Date created:		17 November 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	frei0r
PORTVERSION=	1.2
DISTVERSIONPREFIX=	plugins-
CATEGORIES=	graphics
MASTER_SITES=	http://piksel.no/${PORTNAME}/ \
		ftp://ftp.dyne.org/${PORTNAME}/releases/ \
		http://distfiles.macports.org/${PORTNAME}-plugins/

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Minimalistic plugin API for video effects

LIB_DEPENDS=	cv.2:${PORTSDIR}/graphics/opencv \
		gavl.1:${PORTSDIR}/multimedia/gavl

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

PORTDOCS=	AUTHORS ChangeLog README TODO

OPTIONS=	APIDOC "Install full documentation (requires doxygen)" off \
		MMX "Enable MMX CPU instructions" off

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
USE_GCC=	4.2+
.endif

.if defined(WITH_APIDOC)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
PLIST_SUB+=	APIDOC=""
.else
PLIST_SUB+=	APIDOC="@comment "
.endif

.if !defined(WITH_MMX)
CONFIGURE_ARGS+=--disable-cpuflags
.endif

post-patch:
.if !defined(WITH_APIDOC)
	@${REINPLACE_CMD} -e '/^SUBDIRS/s| doc||' ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|^docsdir.*|docsdir = ${DOCSDIR}|' \
			  -e '/^install-data-am/s| install-docsDATA||' \
				${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|^htmldocsdir.*|htmldocsdir = ${DOCSDIR}|' \
				${WRKSRC}/doc/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
