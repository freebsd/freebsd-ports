# ex:ts=8
# Ports collection makefile for:	jsmin
# Date created:			Jul 18, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jsmin
DISTVERSION=	20071204
CATEGORIES=	devel
MASTER_SITES=	http://www.crockford.com/javascript/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.c

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	The JavaScript Minifier

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	${WRKSRC}
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/jsmin

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
