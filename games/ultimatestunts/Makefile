# New ports collection makefile for:	ultimatestunts
# Date created:		9 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ultimatestunts
PORTVERSION=	0.7.4.1
DISTVERSIONPREFIX=	srcdata-
DISTVERSION=	${PORTVERSION:S/.//g}
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Racing game with elaborate stunts

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		alut.1:${PORTSDIR}/audio/freealut

USE_GETTEXT=	yes
USE_GL=		gl glu
USE_SDL=	sdl image
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openal --program-transform-name=""
CPPFLAGS+=	`${SDL_CONFIG} --cflags`
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
PORT_VERBS=	${PORTNAME} ustunts

post-extract:
	@${FIND} ${WRKSRC} -name CVS|${SED} -e 's| |\\ |g'|${XARGS} ${RM} -rf

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/local/include||;s|-L/usr/local/lib||;\
		/usdatadir=/s|=.*|="${DATADIR}"|;/SDL_CONFIG.*cflags/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^sysconf_DATA/d;/^SUBDIRS/s| data | |' ${WRKSRC}/Makefile.in

post-install:
	@cd ${WRKSRC}/data/&&${COPYTREE_SHARE} "cars environment lang misc music textures\
		textures.dat tiles tracks" ${DATADIR}/
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
	@cd ${PREFIX}/etc/&&${CP} -n ${PORTNAME}.conf.sample ${PORTNAME}.conf
.ifndef NOPORTDOCS
	@cd ${WRKSRC}/doc/&&${COPYTREE_SHARE} . ${DOCSDIR}/
.endif

.include <bsd.port.mk>
