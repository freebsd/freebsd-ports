# ex:ts=8
# New ports collection makefile for:	ksmp3play
# Date created:			Nov 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ksmp3play
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.xanadunet.net/ksmp3play/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An curses-based MP3 player

LIB_DEPENDS=	smpeg.1:${PORTSDIR}/multimedia/smpeg

USE_SDL=	yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		ksmp3play.1

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc --exclude "CVS" -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
