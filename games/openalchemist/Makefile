# New ports collection makefile for:    openalchemist
# Date created:     Sat Oct 01 09:30:00 UTC 2003
# Whom:         Ganael LAPLANCHE <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	openalchemist
PORTVERSION=	0.2.2
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Tetris-like game

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	clanCore-0.8:${PORTSDIR}/devel/clanlib

USE_GNOME=	pkgconfig
MAKE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		DATADIR="${DATADIR}"

# Allow relocation of skins (by default, must be in the skins/ sub-dir)
post-patch:
	@${REINPLACE_CMD} -E -e 's|CL_System::get_exe_path\(\) \+ "skins/|"${DATADIR}/skins/|g' ${WRKSRC}/src/*.cpp

.include <bsd.port.mk>
