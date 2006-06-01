# New ports collection makefile for:	Warsow
# Date created:				31 May 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	warsow
PORTVERSION=	0.11
CATEGORIES=	games
MASTER_SITES=	http://warsow.aditsystems.com/ \
		http://ftp.club-internet.fr/pub/games/nofrag/warsow/ \
		http://wsw.surreal-xenotronic.com/
DISTNAME=	${PORTNAME}_${PORTVERSION}_sdk
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}_${PORTVERSION}_linux.tar.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A fast paced first person shooter game

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

USE_GMAKE=	yes
USE_GL=		yes
USE_SDL=	yes
USE_ZIP=	yes
USE_DOS2UNIX=	linux/sys_linux.c

WRKSRC=		${WRKDIR}/source/source
RELEASEDIR=	${WRKSRC}/release
BASEDIR=	${PREFIX}/lib/${PORTNAME}

post-patch: .SILENT
	${REINPLACE_CMD} -e 's#dllname, RTLD_LAZY#& | RTLD_GLOBAL#' \
		${WRKSRC}/linux/qgl_linux.c
	${REINPLACE_CMD} -e 's#path", "\.#path", "${BASEDIR}#; \
		s#dir", "0#dir", "1#' ${WRKSRC}/qcommon/files.c

do-install:
	${INSTALL_PROGRAM} ${RELEASEDIR}/warsow ${RELEASEDIR}/wsw_server \
		${PREFIX}/bin
	@${MKDIR} ${BASEDIR}/basewsw
	${INSTALL_PROGRAM} ${RELEASEDIR}/basewsw/*.so ${BASEDIR}/basewsw
	@${TAR} xzvf ${_DISTDIR}/${PORTNAME}_${PORTVERSION}_linux.tar.gz \
		-C ${PREFIX}/lib warsow/basewsw/cfgs warsow/basewsw/huds \
		warsow/basewsw/dedicated_autoexec.cfg \
		warsow/basewsw/\*.pk3 && ${CHOWN} -R root:wheel ${BASEDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${TAR} xzvf ${_DISTDIR}/${PORTNAME}_${PORTVERSION}_linux.tar.gz \
		-C ${WRKDIR} warsow/docs && ${CP} -R ${WRKDIR}/warsow/docs/ \
		${DOCSDIR} && ${CHMOD} -R 777 ${WRKDIR}/warsow
.endif

.include <bsd.port.mk>
