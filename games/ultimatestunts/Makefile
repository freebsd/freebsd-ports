# New ports collection makefile for:	ultimatestunts
# Date created:		9 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ultimatestunts
PORTVERSION=	0.7.6.1
PORTREVISION=	3
DISTVERSIONPREFIX=	srcdata-
DISTVERSION=	${PORTVERSION:S/.//g}
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/sourcecode

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Racing game with elaborate stunts

LIB_DEPENDS=	vorbisfile.6:${PORTSDIR}/audio/libvorbis

USE_OPENAL=	al alut
USE_GL=		gl glu
USE_SDL=	sdl image
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openal
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	`${SDL_CONFIG} --cflags`
LDFLAGS+=	-L${LOCALBASE}/lib

PORT_VERBS=	${PORTNAME} ustunts

post-extract:
	@${FIND} ${WRKSRC} -name CVS -print0 | ${XARGS} -0 ${RM} -rf

post-patch:
	@${REINPLACE_CMD} -e \
		's|-I/usr/local/include|| ; \
		 s|-L/usr/local/lib|| ; \
		 /usdatadir=/s|=.*|="${DATADIR}"| ; \
		 /SDL_CONFIG.*cflags/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^sysconf_DATA/d ; \
		 /^SUBDIRS/s| data | |' ${WRKSRC}/Makefile.in

post-install:
.for dir in cars environment lang misc music textures textures.dat tiles tracks
	@cd ${WRKSRC}/data && ${COPYTREE_SHARE} ${dir} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>
