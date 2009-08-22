# ex:ts=8
# Ports collection makefile for:	rawrec
# Date created:			May 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rawrec
PORTVERSION=	0.9.991
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE:S/%SUBDIR%/apps\/sound\/recorders/} \
		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility to record and playback raw audio data

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CPPFLAGS} ${CFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -lm ${PTHREAD_LIBS}"

MAN1=	rawrec.1
MLINKS=	rawrec.1 rawplay.1

PLIST_FILES=	bin/rawplay bin/rawrec

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<linux/soundcard.h>|<sys/soundcard.h>|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rawrec ${PREFIX}/bin
	${LN} -sf rawrec ${PREFIX}/bin/rawplay
	${INSTALL_MAN} ${WRKSRC}/../docs/user/rawrec.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
