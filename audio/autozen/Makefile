# New ports collection makefile for:	autozen
# Date created:				2000-09-16
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	autozen
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.springdaemons.com/soft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adjust brain waves with sound

MAKE_ENV+=	PTHREAD_FLAGS="${PTHREAD_CFLAGS} ${PTHREAD_LIBS}" \
		DATADIR="${DATADIR}" DOCSDIR="${DOCSDIR}" MKDIR="${MKDIR}"

USE_GNOME=	gtk12
USE_PERL5_RUN=	yes

PORTDOCS=	*
MAN1=		autozen.1

post-patch:
	@${RM} -f ${WRKSRC}/autozen ${WRKSRC}/seq2wav
.if exists(/usr/include/sys/soundcard.h)
	@${REINPLACE_CMD} "s=machine/soundcard.h=sys/soundcard.h=g" \
		${WRKSRC}/autozen.c
.endif
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} "s=#%%DOCS%%==g" ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
