# Ports collection makefile for:  falconseye
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	falconseye
PORTVERSION=	1.9.3
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/NetHack-Falcon_s%20Eye%20%28source%29/${PORTVERSION}
DISTNAME=	nethack_source_331_jtp_${PORTVERSION:S/.//g}

MAINTAINER=	kris@FreeBSD.org
COMMENT=	NetHack derivative

RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

NHDIR=		"${PREFIX}/share/falconseyedir"
MAKE_ENV=	NHDIR="${NHDIR}" NETHACKCONFIG="${NETHACKCONFIG}"
NETHACKCONFIG=	${FILESDIR}/x-config
USE_SDL=	sdl
USE_PERL5_BUILD=yes
USE_ZIP=	yes
USE_XORG=	x11 xpm xaw
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -I${LOCALBASE}/include/SDL11
WRKSRC=		${WRKDIR}

post-patch:
	@${PERL} -pi -e "s@<malloc.h>@<stdlib.h>@g" \
	${WRKSRC}/include/jtp_gen.h ${WRKSRC}/win/jtp/jtp_dirx.c \
	${WRKSRC}/win/jtp/jtp_keys.c ${WRKSRC}/win/jtp/jtp_sdl.c \
	${WRKSRC}/win/Qt/qt_win.cpp

do-configure:
	@cd ${WRKSRC}/sys/unix && ${SH} setup.sh symlinks

post-build:
	@cd ${WRKSRC}/util && ${LN} -f recover frecover
	@cd ${WRKSRC}/doc && ${PERL} -p ${FILESDIR}/substitute <nethack.6 >falconseye.6
	@cd ${WRKSRC}/doc && ${PERL} -p ${FILESDIR}/substitute <recover.6 >frecover.6

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/util/recover ${PREFIX}/bin/frecover
	@cd ${WRKSRC}/doc && \
		${INSTALL_MAN} recover.6 ${PREFIX}/man/man6/frecover.6
	@cd ${WRKSRC}/doc && \
		${INSTALL_MAN} nethack.6 ${PREFIX}/man/man6/falconseye.6

.include <bsd.port.mk>
