# New ports collection makefile for:	TinyMUX
# Date created:		1998/05/28
# Whom:			cjohnson
#
# $FreeBSD$
#

PORTNAME=	tinymux
PORTVERSION=	2.6.5.${PATCHLEVEL}
PORTREVISION=	1
CATEGORIES=	games net
MASTER_SITES=	ftp://ftp.tinymux.org/TinyMUX/tinymux-2.6/${PATCHLEVEL}/ \
		http://www.tinymux.org/
DISTNAME=	mux-${PORTVERSION}.unix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Multi-Player FreeForm adventure Program

USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

PATCHLEVEL=	32
WRKSRC=		${WRKDIR}/mux2.6/src
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
# Binaries
.for file in netmux slave
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/sbin
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/../game/bin/dbconvert ${PREFIX}/bin
# Configuration
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
.for file in alias.conf compat.conf mux.config netmux.conf
	${INSTALL_DATA} ${WRKSRC}/../game/${file} \
		${PREFIX}/etc/${PORTNAME}/${file}.sample
.endfor
# Data
	${MKDIR} ${DATADIR}/game/netmux
.for file in Backup Startmux _backupflat.sh
	${INSTALL_SCRIPT} ${WRKSRC}/../game/${file} ${DATADIR}/game/netmux/
.endfor
	${MKDIR} ${DATADIR}/game/netmux/data
.for file in db_check db_load db_unload
	${INSTALL_SCRIPT} ${WRKSRC}/../game/data/${file} \
		${DATADIR}/game/netmux/data
.endfor
	${INSTALL_DATA} ${WRKSRC}/../game/data/netmux.db \
		${DATADIR}/game/netmux/data
	${MKDIR} ${DATADIR}/game/netmux/text
.for file in badsite connect create_reg down full guest help motd \
	news newuser plushelp quit register staffhelp wizhelp wizmotd wiznews
	${INSTALL_DATA} ${WRKSRC}/../game/text/${file}.txt \
		${DATADIR}/game/netmux/text
.endfor
# Docs
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ATTACK CHANGES INSTALL NOTES README SGP
	${INSTALL_DATA} ${WRKSRC}/../${file} ${DOCSDIR}
.endfor
.for file in BACKUPS CONFIGURATION CONVERSION CREDITS DISTRIBUTIONS GUESTS \
	LIMITS MEMORY PATCHES REALMS
	${INSTALL_DATA} ${WRKSRC}/../docs/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
