# New ports collection makefile for:	asis
# Date created:				11 Jul 2000
# Whom:					Thomas Quinot <thomas@cuivre.fr.eu.org>
#
# $FreeBSD$
#

PORTNAME=	asis
PORTVERSION=	3.13p
CATEGORIES=	devel
MASTER_SITES=	\
	ftp://ftp.lip6.fr/pub/gnat/${PORTVERSION}/asis/ \
	ftp://cs.nyu.edu/pub/gnat/${PORTVERSION}/asis/
DISTNAME=	asis-${PORTVERSION}-src

MAINTAINER=	thomas@cuivre.fr.eu.org

BUILD_DEPENDS=	adagcc:${PORTSDIR}/lang/gnat

USE_GMAKE=	yes
MAKEFILE=	"${FILESDIR}/Makefile.bsd"
MAKE_ARGS=	GMAKE=${GMAKE} PORTVERSION=${PORTVERSION} \
		LN=${LN}

do-install:
	@ ${MKDIR} ${PREFIX}/lib/asis || true
	@ ${INSTALL_DATA} ${WRKSRC}/asis/*.ad? ${WRKSRC}/gnat/*.ad? ${WRKSRC}/obj/*.ali ${PREFIX}/lib/asis
	@ ${INSTALL_DATA} ${WRKSRC}/obj/libasis.a ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/libasis-${PORTVERSION}.so.1 ${PREFIX}/lib
	@ ${LN} -sf ${PREFIX}/lib/libasis-${PORTVERSION}.so.1 ${PREFIX}/lib/libasis-${PORTVERSION}.so

	@ ${INSTALL_PROGRAM} ${WRKSRC}/asistant.prg ${PREFIX}/bin/asistant
	@ ${INSTALL_PROGRAM} ${WRKSRC}/display_source ${WRKSRC}/gnatelim ${WRKSRC}/gnatstub ${PREFIX}/bin

post-install:
	@ ${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/asis || true
	@ ${INSTALL_DATA} ${WRKSRC}/documentation/* ${PREFIX}/share/doc/asis
	@ ${INSTALL_DATA} ${WRKSRC}/examples/ds/README ${PREFIX}/share/doc/asis/README.ds
	@ ${INSTALL_DATA} ${WRKSRC}/tools/asistant/asistant.ug ${PREFIX}/share/doc/asis/README.asistant
	@ ${INSTALL_DATA} ${WRKSRC}/tools/gnatelim/README ${PREFIX}/share/doc/asis/README.gnatelim
	@ ${INSTALL_DATA} ${WRKSRC}/tools/gnatstub/README ${PREFIX}/share/doc/asis/README.gnatstub
.endif

.include <bsd.port.mk>
