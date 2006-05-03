# New ports collection makefile for:	ac3dev
# Date created:				23 Jun 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ac3dec
PORTVERSION=	0.6.1
CATEGORIES=	audio
MASTER_SITES=	http://liba52.sourceforge.net/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software for research in digital audio coding/decoding

ONLY_FOR_ARCHS=	i386 alpha

GNU_CONFIGURE=	yes

PORTDOCS=	README
PLIST_FILES=	bin/ac3dec bin/extract_ac3

post-patch:
.for file in Makefile.in libac3/Makefile.in tools/Makefile.in
	@${REINPLACE_CMD} -e \
		's|^CFLAGS =.*$$|CFLAGS = @CFLAGS@|g' ${WRKSRC}/${file}
.endfor
.for file in output.c output_linux.c
	@${REINPLACE_CMD} -e \
		's|machine/soundcard.h|sys/soundcard.h|g' ${WRKSRC}/${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
