# Created by: Mario S F Ferreira <lioux@linf.unb.br> et al.
# $FreeBSD$

PORTNAME=	electric
PORTVERSION=	7.0.0
PORTREVISION=	5
CATEGORIES=	cad
MASTER_SITES=	GNU
DISTNAME=	${PORTNAME}-${PORTVERSION:C/^(...)\./\1/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sophisticated electrical CAD system

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

USES=		motif

FEATURES=	MOTIF

OPTIONS_DEFINE=	T1LIB NLS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=T1LIB
T1LIB_DESC=	Use T1lib Type1 font library

T1LIB_LIB_DEPENDS=	libt1.so:devel/t1lib
T1LIB_VARS=	FEATURES+=T1LIB
NLS_USES=	gettext
NLS_VARS=	FEATURES+=INT
OPTIMIZED_CFLAGS_VARS= 	FEATURES+=OPT

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/electric/lib/|${DATADIR}/lib/|; \
		s|/usr/share/electric/doc/|${DOCSDIR}/|; \
		s|/usr/bin/|${LOCALBASE}/bin/|; \
		s|${LOCALBASE}/bin/sort|${SORT}|' \
		${WRKSRC}/src/include/config.h
	@${REINPLACE_CMD} -e 's|/usr/share/electric/lib|${DATADIR}/lib|; \
		s|/usr/share/electric/doc|${DOCSDIR}|; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/X11R6/|${LOCALBASE}/|' ${WRKSRC}/configure
.for FEATURE in ${FEATURES}
	@${REINPLACE_CMD} -e 's|#%%${FEATURE}%%||g' ${WRKSRC}/Makefile.in
.endfor

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/electric

.include <bsd.port.mk>
