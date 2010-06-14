# New ports collection makefile for:	gxemul
# Date created:		15 May 2005
# Whom:			Janni
#
# $FreeBSD$
#

PORTNAME=	gxemul
PORTVERSION=	0.6.0
CATEGORIES=	emulators
MASTER_SITES=	http://gxemul.sourceforge.net/src/ \
		http://gavare.se/gxemul/src/

MAINTAINER=	imp@FreeBSD.org
COMMENT=	Instruction-level machine emulator

OPTIONS=	X11	 "X11 support" on

HAS_CONFIGURE=	yes
ALL_TARGET=	build
MAKE_JOBS_UNSAFE=	yes

MAN1=		gxemul.1
PORTDOCS=	*
PLIST_FILES=	bin/gxemul

.include <bsd.port.pre.mk>

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--disable-x
.else
USE_XORG=	x11
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|/usr/X11R6|${LOCALBASE}|g; \
		 s|-O[0-9]?||g; \
		 s|-f[a-zA-Z-]+||g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gxemul ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/man/gxemul.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} -p ${DOCSDIR}/components
	${MKDIR} -p ${DOCSDIR}/machines
	${INSTALL_DATA} ${WRKSRC}/doc/components/* ${DOCSDIR}/components
	${INSTALL_DATA} ${WRKSRC}/doc/machines/* ${DOCSDIR}/machines
	${INSTALL_DATA} `find ${WRKSRC}/doc/ -type f -depth 1` ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
