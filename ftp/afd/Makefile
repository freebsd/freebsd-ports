# ex:ts=8
# New ports collection makefile for:	afd
# Date created:			Apr 26, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	afd
PORTVERSION=	1.2.6
CATEGORIES=	ftp
MASTER_SITES=	http://www.dwd.de/general/GBTI/afd/download/ \
		ftp://ftp.dwd.de/pub/afd/
DISTNAME=	src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

FORBIDDEN=	"Installs 88 setuid root applications; disaster waiting to happen"

USE_MOTIF=	yes
MAKE_ENV=	BINMODE=${BINMODE} \
		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

post-patch:
	@find ${WRKSRC} -name Makefile | xargs \
		${PERL} -pi -e "s,^(INST(ALL)?DIR *)= .*,\1= ${PREFIX}/bin,g ; \
				s,cp -p,cp,g"
	@${PERL} -pi -e "s,%%CFLAGS%%,${CFLAGS},g" ${WRKSRC}/Include.mk.freebsd
	@${PERL} -pi -e "s,^SBINDIR  = .*,SBINDIR  = ${PREFIX}/sbin,g" ${WRKSRC}/afd_mon/Makefile

pre-build:
	@(cd ${WRKSRC} ; ${RM} -f Include.mk ; \
	  ${LN} -s Include.mk.freebsd Include.mk)

.include <bsd.port.mk>
