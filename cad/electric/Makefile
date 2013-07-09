# Created by: Mario S F Ferreira <lioux@linf.unb.br> et al.
# $FreeBSD$

PORTNAME=	electric
PORTVERSION=	7.0.0
PORTREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/^(...)\./\1/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sophisticated electrical CAD system

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	T1LIB NLS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	T1LIB
T1LIB_DESC=	Use T1lib Type1 font library

USES=		motif

.include <bsd.port.options.mk>

FEATURES+=	MOTIF

.if ${PORT_OPTIONS:MT1LIB}
LIB_DEPENDS+=	t1.5:${PORTSDIR}/devel/t1lib
FEATURES+=	T1LIB
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
FEATURES+=	INT
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
FEATURES+=	OPT
.endif

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
	${STRIP_CMD} ${PREFIX}/bin/electric

.include <bsd.port.mk>
