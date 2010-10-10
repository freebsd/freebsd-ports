# New ports collection makefile for:	jcode.pl
# Date created:		20 February 1998
# Whom:			sada
#
# $FreeBSD$
#

PORTNAME=	jcode.pl
PORTVERSION=	2.13
CATEGORIES=	japanese perl5
MASTER_SITES=	http://srekcah.org/jcode/
EXTRACT_SUFX=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl library for Japanese character code conversion

USE_PERL5_RUN=		yes
NO_WRKSUBDIR=		yes
NO_BUILD=		yes
EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.

PLIST_FILES=	%%SITE_PERL%%/${PORTNAME}

do-install:
	${MKDIR} ${INSTALL_DIR}/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} ${SITE_PERL}/${PORTNAME}

.include <bsd.port.mk>
