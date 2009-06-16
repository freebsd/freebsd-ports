# New ports collection makefile for:    fillets-ng
# Date created:         11 Oct 2005
# Whom:                 Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	fillets-ng
PORTVERSION=	0.9.0
CATEGORIES=	games
MASTER_SITES=	SF/fillets
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-data-${DATAVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A wonderful puzzle game

USE_SDL=	sdl mixer image ttf
USE_LUA=	5.1
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV=		CPPFLAGS="-I${LUA_INCDIR}" LDFLAGS="-L${LUA_LIBDIR}"
CONFIGURE_ARGS=		--datadir="${DATADIR}" --with-lua="${LOCALBASE}"

OPTIONS=	FRIBIDI	"Enable fribidi support" on

DATAVERSION=	${PORTVERSION}

PORTDOCS=	*

MAN6=		fillets.6

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FRIBIDI)
LIB_DEPENDS+=	fribidi.0:${PORTSDIR}/converters/fribidi
.endif

post-patch:
	@${REINPLACE_CMD} -e '/LIBS/ s|-llualib[50.]*||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^\(AM_CPPFLAGS.*(datadir)\)/.*|\1"\\"|' \
		${WRKSRC}/src/gengine/Makefile.in
.if defined(WITHOUT_FRIBIDI)
	@${REINPLACE_CMD} -e \
		's|FRIBIDI_CFLAGS=$$pkg_cv_FRIBIDI_CFLAGS||; s|FRIBIDI_LIBS=$$pkg_cv_FRIBIDI_LIBS||; s|have_fribidi="yes"|have_fribidi="no"|' \
		${WRKSRC}/configure
.endif

post-install:
	${MKDIR} ${DATADIR}
	cd ${WRKDIR}/${PORTNAME}-data-${DATAVERSION} && \
		${COPYTREE_SHARE} "font	images music script sound" ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKDIR}/${PORTNAME}-data-${DATAVERSION}/doc; \
		${COPYTREE_SHARE} "*" ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
