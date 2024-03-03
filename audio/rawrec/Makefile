PORTNAME=	rawrec
PORTVERSION=	0.9.991
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SUNSITE/apps/sound/recorders \
		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	antonfb@hesiod.org
COMMENT=	Utility to record and playback raw audio data
WWW=		https://sourceforge.net/projects/rawrec/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/copyright

USES=		gmake

WRKSRC=		${WRKDIR}/${DISTNAME}/src

MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CPPFLAGS} ${CFLAGS}" \
		LDFLAGS="${LDFLAGS} -lm -lpthread"

PLIST_FILES=	bin/rawplay \
		bin/rawrec \
		share/man/man1/rawplay.1.gz \
		share/man/man1/rawrec.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rawrec ${STAGEDIR}${PREFIX}/bin
	${LN} -sf rawrec ${STAGEDIR}${PREFIX}/bin/rawplay
	${INSTALL_MAN} ${WRKSRC}/../docs/user/rawrec.1 \
	    ${STAGEDIR}${PREFIX}/share/man/man1
	${LN} -sf rawrec.1 ${STAGEDIR}${PREFIX}/share/man/man1/rawplay.1

.include <bsd.port.mk>
