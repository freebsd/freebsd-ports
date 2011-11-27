# New ports collection makefile for:	frotz
# Date created:				16 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	frotz
PORTVERSION=	2.43
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF \
		http://www.ifarchive.org/if-archive/infocom/interpreters/frotz/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Infocom games interpreter

LICENSE=	GPLv2 # (or later)

MAKE_ARGS=	CC="${CC}" OPTS="${CFLAGS}" PREFIX="${PREFIX}" \
		CONFIG_DIR="${PREFIX}/etc" SOUND_DEFS="-DOSS_SOUND" \
		SOUND_DEV="/dev/dsp" INCL="" LIB=""
MAKE_JOBS_SAFE=	yes

MAN6=		frotz.6
PORTDOCS=	BUGS HOW_TO_PLAY README
PORTEXAMPLES=	frotz.conf-big frotz.conf-small
PLIST_FILES=	bin/frotz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/frotz ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/frotz.6 ${MANPREFIX}/man/man6
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for ex in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/${ex} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
