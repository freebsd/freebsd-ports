# New ports collection Makefile for:	praat
# Date created:		21-Feb-2006
# Whom:			jbacon
#
# $FreeBSD$
#

PORTNAME=	praat
PORTVERSION=	4.4.10
CATEGORIES=	audio science
MASTER_SITES=	http://www.neuro.mcw.edu/~bacon/Ports/distfiles/Praat/4410/
DISTNAME=	praat4410_sources

MAINTAINER=	bacon@smithers.neuro.mcw.edu
COMMENT=	Phonetics by Computer

USE_X_PREFIX=	yes
USE_MOTIF=	yes
WRKSRC=		${WRKDIR}/sources_4410
MAKEFILE=	makefile
PLIST_FILES=	bin/praat

post-patch:
	@${FIND} ${WRKSRC} -name Makefile -exec \
		${REINPLACE_CMD} -e 's|^CFLAGS =|CFLAGS +=|' "{}" \;
	@${CP} ${WRKSRC}/makefiles/makefile.defs.freebsd.dynamic \
		${WRKSRC}/makefile.defs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/praat ${PREFIX}/bin

.include <bsd.port.mk>
