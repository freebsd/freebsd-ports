# New ports collection makefile for:	colorgcc
# Date created:		2009-07-21
# Whom:			Sofian Brabez <sbrabez@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	colorgcc
PORTVERSION=	1.3.2
CATEGORIES=	devel misc
MASTER_SITES=	http://schlueters.de/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.txt
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Perl script to colorize the terminal ouput of GCC

RUN_DEPENDS=	${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor
BUILD_DEPENDS=	${RUN_DEPENDS}

PLIST_FILES=	bin/${PORTNAME} \
		share/examples/${PORTNAME}/${PORTNAME}rc
PLIST_DIRS=	share/examples/${PORTNAME}
SUB_FILES=	pkg-message

NO_BUILD=yes

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${WRKSRC}/${PORTNAME}

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${INSTALL_DATA} ${FILESDIR}/${PORTNAME}rc ${EXAMPLESDIR}/

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
