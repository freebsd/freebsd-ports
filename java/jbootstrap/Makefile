# New ports collection makefile for:	jbootstrap
# Date created:				7 July 2005
# Whom:					<glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jbootstrap
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	# http://www.eyesbeyond.com/freebsddom/java/jbootstrap.html

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java bootstrap tools

RUN_DEPENDS=	${LOCALBASE}/bin/jikes:${PORTSDIR}/java/jikes

USE_PERL5_RUN=	yes
MAKE_FLAGS+=	BINDIR=${PREFIX}/${PORTNAME}/bin \
		LIBEXECDIR=${PREFIX}/${PORTNAME}/libexec
.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install-doc
.endif

RESTRICTED=	"Redistribution of pre-compiled binaries is not permitted"

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		This port requires perl 5.8 or above.
.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE= Please fetch ${DISTNAME}${EXTRACT_SUFX} from http://www.eyesbeyond.com/freebsddom/java/jbootstrap.html and place it in ${DISTDIR}
.endif

.include <bsd.port.post.mk>
