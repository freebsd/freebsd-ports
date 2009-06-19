# New ports collection Makefile for:	praat
# Date created:		21-Feb-2006
# Whom:			jbacon
#
# $FreeBSD$
#

PORTNAME=	praat
PORTVERSION=	4.6.39
PORTREVISION=	1
CATEGORIES=	audio science
MASTER_SITES=	http://www.neuro.mcw.edu/~bacon/Ports/distfiles/Praat/4639/ \
		http://www.fon.hum.uva.nl/praat/
DISTNAME=	praat4639_sources

MAINTAINER=	jwbacon@tds.net
COMMENT=	Phonetics by Computer

USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*Makefile
USE_MOTIF=	yes
WRKSRC=		${WRKDIR}/sources_4639
MAKEFILE=	makefile
PLIST_FILES=	bin/praat

MAN1=		praat.1

post-patch:
	@${REINPLACE_CMD} -e 's/ log2/ NUMlog2/' ${WRKSRC}/dwtools/Sound_extensions.c
	@${FIND} ${WRKSRC} -name Makefile -exec \
		${REINPLACE_CMD} -e 's|^CFLAGS =|CFLAGS +=|' "{}" \;
	@${CP} ${WRKSRC}/makefiles/makefile.defs.freebsd.dynamic \
		${WRKSRC}/makefile.defs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/praat ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/praat.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
