# New ports collection makefile for:	ultimatestunts
# Date created:		9 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ultimatestunts
PORTVERSION=	0.7.5.1
PORTREVISION=	6
DISTVERSIONPREFIX=	srcdata-
DISTVERSION=	${PORTVERSION:S/.//g}
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/sourcecode/0.7.5%20release%201

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Racing game with elaborate stunts

USE_GETTEXT=	yes
USE_OPENAL=	al alut
USE_GL=		gl glu
USE_SDL=	sdl image
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openal --program-transform-name=""
CPPFLAGS+=	`${SDL_CONFIG} --cflags`
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
PORT_VERBS=	${PORTNAME} ustunts
MAKE_JOBS_UNSAFE=	yes

post-extract:
	@${FIND} ${WRKSRC} -name CVS|${SED} -e 's| |\\ |g'|${XARGS} ${RM} -rf

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/local/include||;s|-L/usr/local/lib||;\
		/usdatadir=/s|=.*|="${DATADIR}"|;/SDL_CONFIG.*cflags/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^sysconf_DATA/d;/^SUBDIRS/s| data | |' ${WRKSRC}/Makefile.in

post-install:
	@cd ${WRKSRC}/data/&&${COPYTREE_SHARE} "cars environment lang misc music textures\
		textures.dat tiles tracks" ${DATADIR}/
.ifndef NOPORTDOCS
	@cd ${WRKSRC}/doc/&&${COPYTREE_SHARE} . ${DOCSDIR}/
.endif

.include <bsd.port.mk>
