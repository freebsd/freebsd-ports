# New ports collection makefile for:	Ftptool
# Date created:		19 March 1996
# Whom:			janek@gaja.ipan.lublin.pl
#
# $FreeBSD$
#

PORTNAME=	ftptool
PORTVERSION=	4.6
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities
DISTFILES=	Ftptool${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphic ftp shell based on xview

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview
RUN_DEPENDS=	${X11BASE}/bin/textedit:${PORTSDIR}/editors/textedit

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/Ftptool4.6

MAN1=		ftptool.1
PLIST_FILES=	bin/ftptool lib/help/ftptool.info
PLIST_DIRS=	lib/X11/ftptool

# Because lex.l is broken, lex.c is taken from old FreeBSD 1.1 port

post-extract:
	@${CP} ${FILESDIR}/lex.c ${WRKSRC}
	@${RM} -f ${WRKSRC}/lex.l

.include <bsd.port.mk>
