# New ports collection makefile for:	xqf
# Date created:				08 February 1999
# Whom:					steve farrell
#
# $FreeBSD$
#

PORTNAME=	xqf
PORTVERSION=	0.9.12
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Find quake servers

RUN_DEPENDS=	qstat:${PORTSDIR}/games/qstat

USE_GNOME=	gdkpixbuf gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN6=		xqf.6

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/xqfdocs.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
