# ex:ts=8
# Ports collection makefile for:	jsmin
# Date created:			Jul 18, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jsmin
PORTVERSION=	20120702
CATEGORIES=	devel
MASTER_SITES=	https://github.com/douglascrockford/JSMin/tarball/master/
DISTNAME=	douglascrockford-JSMin-${GITVERSION}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	The JavaScript Minifier

GITVERSION=	49a70cf
FETCH_ARGS=	-pRr

PLIST_FILES=	bin/jsmin
PORTDOCS=	README

.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
