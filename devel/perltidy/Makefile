# ex:ts=8
# New ports collection makefile for:	perltidy
# Date created:			Mar 4, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	perltidy
PORTVERSION=	20010406
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ijliao@FreeBSD.org

USE_PERL5=	yes
NO_BUILD=	yes

MAN1=	perltidy.1 perl2web.1

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%MANPREFIX%%|${MANPREFIX}|g" ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/perltidy
.for file in perltidy perl2web tutorial
.for ext in html pod txt
	${CP} ${WRKSRC}/docs/${file}.${ext} ${PREFIX}/share/doc/perltidy/
.endfor
.endfor
.endif

.include <bsd.port.mk>
