# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	vultures
PORTVERSION=	2.3.67
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://ftp.dk.debian.org/getdeb/%SUBDIR%/ \
		http://ftp.heanet.ie/mirrors/www.getdeb.net/getdeb/%SUBDIR%/ \
		http://mirrors.dotsrc.org/getdeb/%SUBDIR%/ \
		http://servingzone.com/mirrors/getdeb/%SUBDIR%/
MASTER_SITE_SUBDIR=	ubuntu/pool/games/v/vulture
PKGNAMESUFFIX=	-eye
DISTNAME=	${PORTNAME:S/s//}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical interface for NetHack 3.4.3

LICENSE=	nethack
LICENSE_NAME=	NETHACK GENERAL PUBLIC LICENSE
LICENSE_FILE=	${WRKSRC}/dat/license
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libpng.so:graphics/png

WRKSRC=		${WRKDIR}/vulture-${PORTVERSION}/nethack
CONFIGURE_WRKSRC=	${WRKSRC}/sys/unix

USES=		bison gmake tar:xz
USE_SDL=	sdl mixer ttf
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	setup.sh
MAKE_JOBS_UNSAFE=	yes

DESKTOP_ENTRIES="Vulture's Eye" "" "" "vulture-nethack" "" ""

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000033
BUILD_DEPENDS+=	flex>0:textproc/flex
MAKE_ENV+=	FLEX="${LOCALBASE}/bin/flex"
.else
MAKE_ENV+=	FLEX="${FLEX}"
.endif

pre-patch:
	@(cd ${WRKSRC}/win && ${LN} -sf ../../vulture)

pre-configure:
	@${CHMOD} a+x ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

post-build:
	@${CAT} ${WRKSRC}/sys/unix/nethack.sh | ${SED} -e \
		'/^HACKDIR/s|=.*|=${PREFIX}/lib/vulture-nethackdir| ; \
		 s|HACKDIR/nethack|HACKDIR/vulture-nethack|' \
		> ${WRKDIR}/vulture-nethack

do-install:
	(cd ${WRKDIR} && ${INSTALL_SCRIPT} vulture-nethack \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vulture-nethackdir
.for i in logfile perm record
	@${ECHO_CMD} -n > ${STAGEDIR}${PREFIX}/lib/vulture-nethackdir/${i}
.endfor
	(cd ${WRKSRC}/dat && ${INSTALL_DATA} license nhdat \
		${STAGEDIR}${PREFIX}/lib/vulture-nethackdir)
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} vulture-nethack \
		${STAGEDIR}${PREFIX}/lib/vulture-nethackdir)
	(cd ${WRKSRC}/util && ${INSTALL_PROGRAM} recover \
		${STAGEDIR}${PREFIX}/lib/vulture-nethackdir)
	(cd ${WRKSRC}/win/vulture/gamedata && ${INSTALL_DATA} defaults.nh \
		${STAGEDIR}${PREFIX}/lib/vulture-nethackdir)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vulture-nethackdir/config
	(cd ${WRKSRC}/win/vulture/gamedata/config && ${INSTALL_DATA} vulture* \
		${STAGEDIR}${PREFIX}/lib/vulture-nethackdir/config)
.for i in fonts graphics manual music sound tiles
	@(cd ${WRKSRC}/win/vulture/gamedata && ${COPYTREE_SHARE} ${i} \
		${STAGEDIR}${PREFIX}/lib/vulture-nethackdir)
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vulture-nethackdir/save

.include <bsd.port.mk>
