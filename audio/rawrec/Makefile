# ex:ts=8
# Ports collection makefile for:	rawrec
# Date created:			May 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rawrec
PORTVERSION=	0.9.97
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	apps/sound/recorders \
		${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-lgnugetopt -lm ${PTHREAD_LIBS} -L${LOCALBASE}/lib"

MAN1=	rawrec.1
MLINKS=	rawrec.1 rawplay.1

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<linux/soundcard.h>|<sys/soundcard.h>|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rawrec ${PREFIX}/bin
	${LN} -sf rawrec ${PREFIX}/bin/rawplay
	${INSTALL_MAN} ${WRKSRC}/../docs/user/rawrec.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
