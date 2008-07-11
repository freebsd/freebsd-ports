# New ports collection makefile for:	Alien Arena 2006
# Date created:		2005-11-12
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	alienarena
PORTVERSION=	2007.610
PORTEPOCH=	1
CATEGORIES=	games linux
MASTER_SITES=	ftp://ftp.simtel.com/pub/gamezone/31/5/17/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}2007-20071011-linux

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Alien Arena 2006 (Linux version)

RUN_DEPENDS=	${DATADIR}/arena/default.cfg:${PORTSDIR}/games/alienarena-data

BROKEN=		needs missing/outdated Linux dependencies (need new linux_compat port and FreeBSD 7); use native instead for now
DEPRECATED=	Has been broken for more than 6 months
EXPIRATION_DATE=2008-09-19

USE_ZIP=	yes
USE_LINUX=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}2007

OPTIONS=	CLIENT "Install client" on \
		DEDICATED "Install dedicated server" on \
		SDL "Install client that uses SDL for sound" on

SUB_LIST=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

LIBDIR=		${PREFIX}/lib/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED) && \
    defined(WITHOUT_SDL)
IGNORE=		needs at least one executable (CLIENT, DEDICATED or SDL)
.endif

.if !defined(WITHOUT_CLIENT) || !defined(WITHOUT_SDL)
# FIXME: needs OpenSSL 0.9.8 and libidn for Linux (not updated/available).
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libcurl.so.3:${PORTSDIR}/ftp/linux-curl \
		${LINUXBASE}/lib/libssl.so.5:${PORTSDIR}/security/linux-openssl
USE_GL=		linux
.endif

.if !defined(WITHOUT_CLIENT)
AA_SCRIPTS+=	linux-alienarena
AA_TARGETS+=	crx
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_DEDICATED)
AA_SCRIPTS+=	linux-alienarena-ded
AA_TARGETS+=	crded
PLIST_SUB+=	DEDICATED=""
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if !defined(WITHOUT_SDL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12
AA_SCRIPTS+=	linux-alienarena-sdl
AA_TARGETS+=	crx.sdl
PLIST_SUB+=	SDL=""
.else
PLIST_SUB+=	SDL="@comment "
.endif

SUB_FILES+=	${AA_SCRIPTS}

do-install:
	${MKDIR} ${LIBDIR}/arena ${LIBDIR}/data1
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} arena/game.so ${LIBDIR}/arena && \
		${INSTALL_PROGRAM} data1/game.so ${LIBDIR}/data1
	${LN} -sf ${DATADIR}/arena/* ${LIBDIR}/arena
	${LN} -sf ${DATADIR}/botinfo ${LIBDIR}
	${LN} -sf ${DATADIR}/data1/* ${LIBDIR}/data1
.for f in ${AA_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/${f} ${PREFIX}/bin
.endfor
.for f in ${AA_TARGETS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${LIBDIR}
.endfor

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
