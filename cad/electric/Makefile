# New ports collection makefile for:	electric
# Date created:		4 May 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	electric
PORTVERSION=	7.0.0
PORTREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/^(...)\./\1/}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A sophisticated electrical CAD system

GNU_CONFIGURE=	yes

OPTIONS=	QT	"Use QT gui (instead of Motif)" off \
		T1LIB	"Use T1lib Type1 font library" on \
		NLS	"Build with internationalization support" on \
		OPT	"Build with optimized CFLAGS" off

.include <bsd.port.pre.mk>

.if defined(WITH_QT)
LIB_DEPENDS+=	qt-mt:${PORTSDIR}/x11-toolkits/qt33
FEATURES+=	QT
.else
USE_MOTIF=	yes
FEATURES+=	MOTIF
.endif

.if !defined(WITHOUT_T1LIB)
LIB_DEPENDS+=	t1.5:${PORTSDIR}/devel/t1lib
FEATURES+=	T1LIB
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
FEATURES+=	INT
.endif

.if defined(WITH_OPT)
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
		s|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|@PTHREAD_LIBS@|${PTHREAD_LIBS:S/"//g}|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/X11R6/|${LOCALBASE}/|' ${WRKSRC}/configure
.for FEATURE in ${FEATURES}
	@${REINPLACE_CMD} -e 's|#%%${FEATURE}%%||g' ${WRKSRC}/Makefile.in
.endfor

post-install:
	${STRIP_CMD} ${PREFIX}/bin/electric

.include <bsd.port.post.mk>
