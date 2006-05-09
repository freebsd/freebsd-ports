# ex:ts=8
# Ports collection makefile for:	lafontaine
# Date created:			Sep 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	lafontaine
PORTVERSION=	0.3R3
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://www.nongnu.org/lafontaine/archives/
DISTNAME=	${PORTNAME}-${PORTVERSION}-20020715

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical logo interpreter

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_GNOME=	gdkpixbuf gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

post-patch:
	@${REINPLACE_CMD} -e 's|pixmaps/$$PACKAGE|$$PACKAGE|g ; \
		 s|-O3|$$CFLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|"\./pixmaps/|PIXMAPDIR "/|g' ${WRKSRC}/src/callbacks.c
	@${REINPLACE_CMD} -e \
		's|exit()|exit(0)|g' ${WRKSRC}/src/proc.c
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|/share/pixmaps|/share|g'
.for file in src/lexer.en.l src/lexer.fr.l
	@${REINPLACE_CMD} -e 's|\.##|.|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
