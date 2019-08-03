# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ascd
PORTVERSION=	0.13.2
PORTREVISION=	1
CATEGORIES=	audio afterstep windowmaker
MASTER_SITES=	http://www.sourcefiles.org/Multimedia/Audio_CD/Other_X11/ \
		AFTERSTEP/stable/rpms/misc-tarballs/:theme
DISTFILES=	${DISTNAME}-src.tgz ${DATAFILES}:theme

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockable CD player for AfterStep or WindowMaker

LICENSE=	GPLv2

BROKEN=		unfetchable

LIB_DEPENDS=	libworkman.so:audio/libworkman

USES=		imake

USE_XORG=	xpm

DATAFILES=	ascd-0.13pr6-themes.tgz
THEMESDIR=	ascd-0.13pr6-themes

post-patch:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" \
		${WRKSRC}/misc/config.h.default > ${WRKSRC}/config.h
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" \
		${WRKSRC}/misc/dirs.h.default > ${WRKSRC}/dirs.h
	@${CAT} ${WRKSRC}/version.h >> ${WRKSRC}/config.h

post-configure:
	@${REINPLACE_CMD} -E '/@(cp|cd)/ s,\(THEMESDIR\),\(DESTDIR\)$$&,g' \
		${WRKSRC}/Makefile

post-install:
	@${ECHO_CMD} "AScd additional themes installation"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Untarring"
	@${TAR} xf ${WRKDIR}/${THEMESDIR}/themes.tar -C \
		${STAGEDIR}${PREFIX}/share/ascd/Themes
	@${ECHO_CMD} "Done."

.include <bsd.port.mk>
