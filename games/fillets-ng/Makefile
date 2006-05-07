# New ports collection makefile for:    fillets-ng
# Date created:         11 Oct 2005
# Whom:                 Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	fillets-ng
PORTVERSION=	0.7.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fillets
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-data-${DATAVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	fillets-ng
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@mail.ru
COMMENT=	A wonderful puzzle game

LIB_DEPENDS=	lua.5:${PORTSDIR}/lang/lua50

USE_SDL=	sdl mixer image ttf
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=		SDL_CONFIG="${SDL_CONFIG}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--datadir="${DATADIR}" --with-lua="${LOCALBASE}"

OPTIONS=	FRIBIDI		"Enable fribidi support"	off

DATAVERSION=	0.7.1

MAN6=		fillets.6

ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if defined(WITH_FRIBIDI)
LIB_DEPENDS+=	fribidi.0:${PORTSDIR}/converters/fribidi
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^\(AM_CPPFLAGS.*(datadir)\)/.*|\1"\\"|' \
		${WRKSRC}/src/gengine/Makefile.in
.if defined(WITHOUT_FRIBIDI)
	@${REINPLACE_CMD} -e \
		's|FRIBIDI_CFLAGS=$$pkg_cv_FRIBIDI_CFLAGS||; s|FRIBIDI_LIBS=$$pkg_cv_FRIBIDI_LIBS||; s|have_fribidi="yes"|have_fribidi="no"|' \
		${WRKSRC}/configure
.endif

post-extract:
	@${TAR} xfz ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-data-${DATAVERSION}${EXTRACT_SUFX} -C ${WRKDIR} \
		${PORTNAME}-data-${DATAVERSION}/font \
		${PORTNAME}-data-${DATAVERSION}/images \
		${PORTNAME}-data-${DATAVERSION}/music \
		${PORTNAME}-data-${DATAVERSION}/script \
		${PORTNAME}-data-${DATAVERSION}/sound

.if !defined(NOPORTDOCS)
		@${MKDIR} ${WRKDIR}/doc
		@${TAR} xfz ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-data-${DATAVERSION}${EXTRACT_SUFX} -C ${WRKDIR}/doc \
			${PORTNAME}-data-${DATAVERSION}/doc
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/game/fillets ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/fillets.6 ${PREFIX}/man/man6/fillets.6
	@cd ${WRKDIR}/${PORTNAME}-data-${DATAVERSION}; \
		${FIND} . -type d -exec ${MKDIR} ${DATADIR}/{} \; ;\
		${FIND} . -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;

.if !defined(NOPORTDOCS)
	@cd ${WRKDIR}/doc/${PORTNAME}-data-${DATAVERSION}/doc; \
		${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; ;\
		${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

.include <bsd.port.post.mk>
