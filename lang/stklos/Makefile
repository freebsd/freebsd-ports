# New ports collection makefile for:	STklos
# Date created:				6 November 2002
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	stklos
PORTVERSION=	0.55
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	The successor of the STk Scheme interpreter

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4 \
		gc.1:${PORTSDIR}/devel/boehm-gc

ONLY_FOR_ARCHS=	i386

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-gtk --disable-gnome
PLIST_SUB=	VERSION="${PORTVERSION}" \
		INFOSECTION="${INFOSECTION}" \
		INFOENTRY="${INFOENTRY}"

MAN1=		stklos-compile.1 stklos-config.1 stklos.1

INFOSECTION=	The Algorithmic Language Scheme
INFOENTRY=	* STklos: (stklos).	The successor of the STk Scheme interpreter

post-patch:
	${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/doc/Makefile.in
	${REINPLACE_CMD} -e 's|^function ||' ${WRKSRC}/utils/stklos-config.in

post-install:
	install-info --section="${INFOSECTION}" --entry="${INFOENTRY}" \
		${PREFIX}/info/stklos.info ${PREFIX}/info/dir

.include <bsd.port.mk>
