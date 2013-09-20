# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	ved
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.berlios.de/pub/ved/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small and fast screen-oriented editor

BUILD_DEPENDS=	smake:${PORTSDIR}/devel/smake

MAN1=		ved.1
PLIST_FILES=	bin/ved %%DATADIR%%/ved.help
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-patch:
	${REINPLACE_CMD} -e 's|^COPTOPT=.*$$|COPTOPT= ${CFLAGS}|g ; \
		 s| gcc| ${CC}|g' ${WRKSRC}/RULES/i386-freebsd-cc.rul
	${REINPLACE_CMD} -e 's|fexecve|fexecve_ved|g' ${WRKSRC}/include/schily.h
	${REINPLACE_CMD} -e 's|fexecve|fexecve_ved|g' ${WRKSRC}/libschily/fexec.c

.for file in ved.h ved.1
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/ved/${file}
.endfor
.for arch in alpha amd64 ia64 sparc64
	cd ${WRKSRC}/RULES \
		&& ${LN} -sf i386-freebsd-cc.rul ${arch}-freebsd-cc.rul
.endfor

do-build:
	(cd ${WRKSRC} && smake)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ved/OBJ/${ARCH}-freebsd-cc/ved \
		${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ved/ved.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ved/ved.help ${DATADIR}

.include <bsd.port.post.mk>
