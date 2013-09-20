# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	multisync
PORTVERSION=	0.82
PORTREVISION=	11
CATEGORIES=	deskutils
MASTER_SITES=	SF/multisync/OldFiles
DISTNAME=	multisync-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Synchronize calendars, addressbooks, and other PIM data

WRKSRC?=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRCMASTER=	${WRKDIR}/multisync-${PORTVERSION}
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui
USES=		gmake pkgconfig
USE_AUTOTOOLS=	automake:env libtool
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes
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
