# New ports collection makefile for:	dice
# Date created:		Wed Jan 30 13:26:52 CET 2002
# Whom:			Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	dice
PORTVERSION=	3.15
PORTREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	http://www.obviously.com/dice/
DISTNAME=	${PORTNAME}-rel-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DICE - The Amiga/embedded/generic 68000 C compiler

USE_REINPLACE=	yes

post-patch:
		@for i in ${WRKSRC}/lib/version.h ${WRKSRC}/include/lib/version.h \
			${WRKSRC}/src/dcpp/main.c ${WRKSRC}/src/dcc/defs.h \
			${WRKSRC}/src/dlink/main.c; \
		do \
			${REINPLACE_CMD} -e 's@/home/dice@${PREFIX}/share/dice@g' $$i; \
		done

		@${CP} ${FILESDIR}/Makefile ${WRKSRC}

		@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} \
			${REINPLACE_CMD} -e 's@__aligned@dice_aligned@g'

do-install:
		@${RM} ${WRKSRC}/doc/loadabs.c.bak
		@for i in ${WRKSRC}/ubin/*; \
		do \
			${INSTALL_PROGRAM} $$i ${PREFIX}/bin; \
		done

		@${MKDIR} ${PREFIX}/share/dice/config
		@for i in ${WRKSRC}/config/* ; \
		do \
			${INSTALL_DATA} $$i ${PREFIX}/share/dice/config; \
		done

.if !defined(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		@for i in ${WRKSRC}/doc/* ; \
		do \
			${INSTALL_DATA} $$i ${DOCSDIR}; \
		done
.endif

.include <bsd.port.mk>
