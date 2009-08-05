# New ports collection makefile for:	xmoontool
# Date created:			31 December 2005
# Whom:				Frank W. Josellis <frank@dynamical-systems.org>
#
# $FreeBSD$
#

PORTNAME=	xmoontool
PORTVERSION=	3.0.3
PORTREVISION=	5
CATEGORIES=	astro
MASTER_SITES=	http://www.senax.net/xmoontool/

MAINTAINER=	frank@dynamical-systems.org
COMMENT=	A version of John Walker's classical moontool for X11/Motif

USE_MOTIF=	yes

MAN1=		xmoontool.1
PORTDOCS=	NOTES
PLIST_FILES=	bin/xmoontool

.if defined(WITHOUT_LIBNOVA)
MAKE_ENV+=	WITHOUT_LIBNOVA=yes
.else
LIB_DEPENDS+=	nova:${PORTSDIR}/astro/libnova
.endif

pre-everything::
.if !defined(WITHOUT_LIBNOVA)
	@${ECHO_MSG} "You can disable libnova support by defining WITHOUT_LIBNOVA"
.endif

pre-configure:
.if !defined(WITHOUT_DEFAULT_COLOR)
	@${ECHO_MSG} "For use with monochrome displays try to set WITHOUT_DEFAULT_COLOR"
.endif

do-configure:
.if defined(WITHOUT_DEFAULT_COLOR)
	@${REINPLACE_CMD} -e 's|-DDEFAULT_COLOR||g' ${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmoontool ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmoontool.1 ${PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
