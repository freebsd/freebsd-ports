# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ultimatestunts
PORTVERSION=	0.7.7.1
DISTVERSIONPREFIX=	srcdata-
DISTVERSION=	${PORTVERSION:S/.//g}
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/sourcecode

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Racing game with elaborate stunts

LICENSE=	GPLv2

LIB_DEPENDS=	vorbisfile.6:${PORTSDIR}/audio/libvorbis

OPTIONS_DEFINE=	DOCS

USES=		gettext openal:al,alut pkgconfig
USE_GL=		gl glu
USE_SDL=	sdl image
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openal
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	$$(pkgconf --cflags-only-I sdl) -I${LOCALBASE}/include
LDFLAGS+=	$$(pkgconf --libs-only-L sdl) -L${LOCALBASE}/lib

PORT_VERBS=	${PORTNAME} ustunts

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	@${FIND} ${WRKSRC} -name ".svn" -print0 | ${XARGS} -0 ${RM} -rf

post-patch:
	@${REINPLACE_CMD} -e \
		's|-I/usr/local/include|| ; \
		 s|-L/usr/local/lib||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^sysconf_DATA/s|^|#| ; \
		 /^SUBDIRS/s| data | |' ${WRKSRC}/Makefile.in

post-install:
.for dir in cars environment lang misc music textures textures.dat tiles tracks
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} ${dir} ${DATADIR})
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
