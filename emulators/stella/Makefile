# New ports collection makefile for:   	stella-1.1
# Date created:				March 4, 1999
# Whom:					Jacques Vidrine <nectar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stella
PORTVERSION=	1.1
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.eos.ncsu.edu/pub/bsvc/stella/1.1/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	nectar@FreeBSD.org

USE_XLIB=	yes

PORTTOP=	${WRKDIR}/${PKGNAME}
WRKSRC=		${PORTTOP}/src/build
MAKEFILE=	makefile
ALL_TARGET=	freebsd-x

USE_XLIB=	yes

ROMSDIR=	${PREFIX}/share/stella/roms
ROMS=		ELK.BIN OKIEDOKE.BIN OYSTR29.BIN TEST.BIN TPS.BIN
DOCSDIR=	${PREFIX}/share/doc/stella
DOCS=		docs/Stella.pdf games/docs/elk.doc games/docs/okiedoke.doc \
		games/docs/oystron.doc games/docs/tps.doc

post-build:
	@(cd ${PORTTOP}/src/ui/sound && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} oss)

do-install:
.for exe in src/build/xstella src/ui/sound/stella-sound
	${INSTALL_PROGRAM} ${PORTTOP}/${exe} ${PREFIX}/bin/
.endfor
	${MKDIR} ${ROMSDIR}
.for rom in ${ROMS}
	${INSTALL_DATA} ${PORTTOP}/games/ROMS/${rom} ${ROMSDIR}/
.endfor
	${INSTALL_DATA} ${PORTTOP}/src/emucore/stella.pro \
		${PREFIX}/share/stella/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${PORTTOP}/${doc} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
