# New ports collection makefile for:	xpad
# Date created:		6 March 2002
# Whom:			Guillaume Paquet <amyfoub@videotron.ca>
#
# $FreeBSD$
#

PORTNAME=	xpad
PORTVERSION=	1.9.1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	amyfoub@videotron.ca
COMMENT=	A virtual note-pad system for your X11 desktop

WRKSRC=		${WRKDIR}/xpad-${PORTVERSION}

USE_GNOME=	gtk20

HAS_CONFIGURE= yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAN1=		xpad.1
MANCOMPRESSED=	no

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xpad
	${INSTALL_MAN} ${WRKSRC}/doc/README ${PREFIX}/share/doc/xpad/
	@${MKDIR} ${PREFIX}/share/examples/xpad
	${INSTALL_MAN} ${WRKSRC}/xpad.desktop ${PREFIX}/share/examples/xpad/
	@${CAT} pkg-message
.endif
	@${RM} /xpad.desktop

.include <bsd.port.mk>
