# New ports collection makefile for:	multisync
# Date created:			25 Nov 2003
# Whom:				Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$

PORTNAME?=	multisync
PORTVERSION=	0.81
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	multisync
DISTNAME=	multisync-${PORTVERSION}

MAINTAINER?=	pav@FreeBSD.org
COMMENT?=	Synchronize calendars, addressbooks and other PIM data

PATCH_DEPENDS+=	${LOCALBASE}/share/automake17/depcomp:${PORTSDIR}/devel/automake17

WRKSRC?=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRCMASTER=	${WRKDIR}/multisync-${PORTVERSION}
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui
USE_GMAKE=	yes
USE_LIBTOOL_VER=	14
USE_X_PREFIX=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

AUTOMAKE_FILES=	missing install-sh mkinstalldirs config.guess config.sub depcomp

post-patch:
	@${FIND} ${WRKDIR} -type l -delete
.for FILE in ${AUTOMAKE_FILES}
	@${CP} -f ${LOCALBASE}/share/automake17/${FILE} ${WRKSRC}
	@${CP} -f ${LOCALBASE}/share/automake17/${FILE} ${WRKSRCMASTER}
.endfor
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-lpthread||'

post-configure:
	${CP} ${LOCALBASE}/bin/libtool14 ${WRKSRC}/libtool

.include <bsd.port.mk>
