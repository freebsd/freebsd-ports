# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rawrec
PORTVERSION=	0.9.991
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SUNSITE/apps/sound/recorders \
		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to record and playback raw audio data

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/copyright

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USES=		gmake
MAKE_ARGS=	CC="${CC}" CFLAGS="${CPPFLAGS} ${CFLAGS}" \
		LDFLAGS="${LDFLAGS} -lm -lpthread"

PLIST_FILES=	bin/rawplay bin/rawrec man/man1/rawplay.1.gz man/man1/rawrec.1.gz

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<linux/soundcard.h>|<sys/soundcard.h>|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rawrec ${STAGEDIR}${PREFIX}/bin
	${LN} -sf rawrec ${STAGEDIR}${PREFIX}/bin/rawplay
	${INSTALL_MAN} ${WRKSRC}/../docs/user/rawrec.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${LN} -sf rawrec.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/rawplay.1

.include <bsd.port.mk>
