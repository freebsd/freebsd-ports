# New ports collection makefile for:	elk
# Date created:		08 March 1995
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	elk
PORTVERSION=	3.0.3
CATEGORIES=	lang
MASTER_SITES=	http://www-rn.informatik.uni-bremen.de/software/elk/dist/
DISTNAME=	elk-3.0

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	An embeddable Scheme interpreter

USE_XLIB=	yes
ALL_TARGET=	default
MAN1=		elk.1

post-patch:
	@${CP} ${WRKSRC}/config/untested/386pc-freebsd2.1-cc \
		${WRKSRC}/config/system
	@${CP} ${WRKSRC}/config/sites/386pc-freebsd2.1 \
		${WRKSRC}/config/site

pre-install:
	@${MKDIR} ${PREFIX}/share/elk

#
# we install the scheme binary as ${PREFIX}/bin/elk
# to avoid a clash with mit-scheme.
#
post-install:
	${INSTALL_PROGRAM} ${PREFIX}/share/elk/bin/scheme ${PREFIX}/bin/elk
	@${MKDIR} ${PREFIX}/include/elk
	${CP} -R ${PREFIX}/share/elk/include/* ${PREFIX}/include/elk
.for dir in bin include
	@${RM} -rf ${PREFIX}/share/elk/${dir}
.endfor
	@${INSTALL_MAN} ${WRKSRC}/doc/man/elk.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
