# New ports collection makefile for:	STklos
# Date created:				6 November 2002
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	stklos
PORTVERSION=	0.82
PORTREVISION=	2
CATEGORIES=	lang scheme
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	The successor of the STk Scheme interpreter

LIB_DEPENDS=	gmp.7:${PORTSDIR}/math/libgmp4 \
		gc.1:${PORTSDIR}/devel/boehm-gc

ONLY_FOR_ARCHS=	i386 amd64

USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib
PLIST_SUB=	VERSION="${PORTVERSION}"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk	\
		--disable-gnome	\
		--enable-threads=none

MAN1=		stklos-compile.1 stklos-config.1 stklos-genlex.1 stklos.1 \
		stklos-install.1

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|-@VERSION@||' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|^function ||' \
		${WRKSRC}/utils/stklos-config.in \
		${WRKSRC}/utils/stklos-ext-install \
		${WRKSRC}/utils/stklos-install
	@${REINPLACE_CMD} -e 's|$UID = 0|`id -u` -eq 0|' \
		${WRKSRC}/utils/stklos-ext-install \
		${WRKSRC}/utils/stklos-install
	@${REINPLACE_CMD} -e '/&&/s|make|gmake|; /&&/s|configure|./configure|' \
		${WRKSRC}/utils/stklos-install

.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E -e 's/^(install-data-am:).*/\1 install-man install-schemeDATA/' \
		-e '/install-docpdfDATA install-man install-schemeDATA/d' \
		${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.mk>
