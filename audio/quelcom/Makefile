# New ports collection makefile for:   quelcom
# Date created:        27 December 2000
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	quelcom
PORTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.etse.urv.es/~dmanye/quelcom/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of command-line utilities for MP3 and wave files

USE_GETOPT_LONG=yes
USE_GMAKE=	yes
MAKEFILE=	makefile

MAN1=		qmp3check.1 qmp3cut.1 qmp3info.1 qmp3join.1 qmp3report.1 \
		qwavcut.1 qwavfade.1 qwavheaderdump.1 qwavinfo.1 qwavjoin.1 \
		qwavsilence.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
BROKEN=		"does not build on FreeBSD 5.x; cout.form cannot be used with GCC 3.x"
.endif

do-install:
.for F in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/${F} ${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/src/${F:S/.1//g} ${PREFIX}/bin
.endfor

.include <bsd.port.post.mk>
