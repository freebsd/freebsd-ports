# New ports collection makefile for:	cuetools
# Date created:		30 December 2003
# Whom:			Vincent Tantardini <vinc@FreeBSD-fr.org>
#
# $FreeBSD$
#

PORTNAME=	cuetools
PORTVERSION=	0.5.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of utilities for working with cue files and toc files

USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" prefix="${PREFIX}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

PORTDOCS=	ChangeLog README cuerename formats useage
PLIST_FILES=	bin/cuebreakpoints bin/cueconvert bin/cuerename

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README doc/cuerename doc/formats doc/useage
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
