# ex:ts=8
# New ports collection makefile for:	axel
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	axel
PORTVERSION=	0.96
CATEGORIES=	ftp
MASTER_SITES=	http://www.lintux.cx/downloads/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt \
		intl:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
MAKE_ENV=	LFLAGS="-L${LOCALBASE}/lib -lgnugetopt -lintl"

MAN1=		axel.1

post-patch:
	@${PERL} -pi -e "s,-pthread,${PTHREAD_LIBS},g ; \
		s,^(CFLAGS = -O3),#\1,g ; \
		s,gcc,${CC},g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/axel ${PREFIX}/bin/axel
	${INSTALL_DATA} ${WRKSRC}/axelrc.example ${PREFIX}/etc/axelrc
	${INSTALL_MAN} ${WRKSRC}/axel.1 ${PREFIX}/man/man1/axel.1
.for lang in de nl
	${INSTALL_DATA} ${WRKSRC}/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/axel.mo
.endfor

.include <bsd.port.mk>
