# New ports collection makefile for:	asis
# Date created:				11 Jul 2000
# Whom:					Thomas Quinot <thomas@cuivre.fr.eu.org>
#
# $FreeBSD$
#

PORTNAME=	asis
PORTVERSION=	3.15p
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://gd.tuwien.ac.at/languages/ada/gnat/3.15p/asis/ \
		ftp://ftp.cs.kuleuven.ac.be/pub/Ada-Belgium/mirrors/gnu-ada/3.15p/asis/
DISTNAME=	asis-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNAT implementation of the Ada Semantic Interface Specification

BUILD_DEPENDS=	gnatgcc:${PORTSDIR}/lang/gnat

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

BROKEN= 	Does not build after gpl 2009 update to lang/gnat
DEPRECATED=	has been broken for 3 months
EXPIRATION_DATE=2010-01-08

WITHOUT_CPU_CFLAGS=	yes
CFLAGS=		-O2 -pipe
USE_GMAKE=	yes
MAKEFILE=	"${FILESDIR}/Makefile.bsd"
MAKE_ARGS=	GMAKE=${GMAKE} PORTVERSION=${PORTVERSION} \
		LN=${LN}

do-install:
	@${MKDIR} ${PREFIX}/lib/asis
	@${INSTALL_DATA} ${WRKSRC}/asis/*.ad? ${WRKSRC}/gnat/*.ad? ${WRKSRC}/obj/*.ali ${PREFIX}/lib/asis
	@${INSTALL_DATA} ${WRKSRC}/obj/libasis.a ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/libasis-${PORTVERSION}.so.1 ${PREFIX}/lib
	@${LN} -sf ${PREFIX}/lib/libasis-${PORTVERSION}.so.1 ${PREFIX}/lib/libasis-${PORTVERSION}.so

	@${INSTALL_PROGRAM} ${WRKSRC}/asistant.prg ${PREFIX}/bin/asistant
	@${INSTALL_PROGRAM} ${WRKSRC}/display_source ${WRKSRC}/gnatelim ${WRKSRC}/gnatstub ${PREFIX}/bin

post-install:
	@${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/documentation/* ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/ds/README ${DOCSDIR}/README.ds
	@${INSTALL_DATA} ${WRKSRC}/tools/asistant/asistant.ug ${DOCSDIR}/README.asistant
	@${INSTALL_DATA} ${WRKSRC}/tools/gnatelim/README ${DOCSDIR}/README.gnatelim
	@${INSTALL_DATA} ${WRKSRC}/tools/gnatstub/README ${DOCSDIR}/README.gnatstub
.endif

.include <bsd.port.post.mk>
