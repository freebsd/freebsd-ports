# ex:ts=8
# New ports collection makefile for:	perltidy
# Date created:			Mar 4, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	perltidy
PORTVERSION=	20011231
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

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in BUGS ChangeLog perl2web perltidy tutorial
.for ext in html txt
	${INSTALL_DATA} ${WRKSRC}/docs/${file}.${ext} ${DOCSDIR}
.endfor
.endfor
.endif

.include <bsd.port.mk>
