# New ports collection makefile for:   ved
# Date created:        31 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ved
PORTVERSION=	1.7
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.berlios.de/pub/ved/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small and fast screen-oriented editor

USE_REINPLACE=	yes
USE_GMAKE=	yes

MAN1=		ved.1
PLIST_FILES=	bin/ved %%DATADIR%%/ved.help
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		"Does not compile on ia64"
.endif

post-patch:
	${REINPLACE_CMD} -e 's|^COPTOPT=.*$$|COPTOPT= ${CFLAGS}|g ; \
		 s| gcc| ${CC}|g' ${WRKSRC}/RULES/i386-freebsd-cc.rul
.for file in ved.h ved.1
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/ved/${file}
.endfor
.for arch in alpha amd64 ia64 sparc64
	cd ${WRKSRC}/RULES \
		&& ${LN} -sf i386-freebsd-cc.rul ${arch}-freebsd-cc.rul
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ved/OBJ/${ARCH}-freebsd-cc/ved \
		${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ved/ved.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ved/ved.help ${DATADIR}

.include <bsd.port.post.mk>
