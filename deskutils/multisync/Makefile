# New ports collection makefile for:	multisync
# Date created:			25 Nov 2003
# Whom:				Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$

PORTNAME?=	multisync
PORTVERSION=	0.82
PORTREVISION=	8
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	multisync
DISTNAME=	multisync-${PORTVERSION}

MAINTAINER?=	pav@FreeBSD.org
COMMENT?=	Synchronize calendars, addressbooks and other PIM data

WRKSRC?=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRCMASTER=	${WRKDIR}/multisync-${PORTVERSION}
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:19:env libtool:15
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

pre-configure:
	@${FIND} ${WRKDIR} -type l -delete
.for FILE in missing install-sh mkinstalldirs config.guess config.sub depcomp
	@${CP} -f ${AUTOMAKE_DIR}/${FILE} ${WRKSRC}
	@${CP} -f ${AUTOMAKE_DIR}/${FILE} ${WRKSRCMASTER}
.endfor
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-lpthread||'

post-configure:
	${CP} ${LIBTOOL} ${WRKSRC}/libtool

.include <bsd.port.mk>
