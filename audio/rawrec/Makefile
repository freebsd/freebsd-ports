# ex:ts=8
# Ports collection makefile for:	rawrec
# Date created:			May 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rawrec
PORTVERSION=	0.9.97
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	apps/sound/recorders \
		${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

WRKSRC=		${WRKDIR}/${DISTNAME}/src
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
USE_GMAKE=	yes

MAN1=	rawrec.1
MLINKS=	rawrec.1 rawplay.1

post-patch:
	@${PERL} -pi -e "s,^CFLAGS =,CFLAGS+=,g ; \
		s,^LDFLAGS =,LDFLAGS+=,g ; \
		s,-lpthread,${PTHREAD_LIBS},g ; \
		s,/usr/local,${PREFIX},g" ${WRKSRC}/Makefile
	@${GREP} -lR "linux/" ${WRKSRC} | ${XARGS} \
		${PERL} -pi -e "s,linux/,machine/,g"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rawrec ${PREFIX}/bin
	${LN} -fs ${PREFIX}/bin/rawrec ${PREFIX}/bin/rawplay
	${INSTALL_MAN} ${WRKSRC}/../docs/user/rawrec.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
