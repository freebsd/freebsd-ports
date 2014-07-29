# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	multisync
PORTVERSION=	0.82
PORTREVISION=	12
CATEGORIES=	deskutils
MASTER_SITES=	SF/multisync/OldFiles
DISTNAME=	multisync-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Synchronize calendars, addressbooks, and other PIM data

WRKSRC?=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
WRKSRCMASTER=	${WRKDIR}/multisync-${PORTVERSION}
USE_GNOME=	gnomeprefix libgnomeui
USES=		gmake libtool pathfix pkgconfig tar:bzip2
USE_AUTOTOOLS=	libtoolize aclocal autoconf automake
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

pre-configure:
	@${FIND} ${WRKDIR} -type l -delete
.for FILE in missing install-sh mkinstalldirs config.guess config.sub depcomp
	@${CP} -f ${AUTOMAKE_DIR}/${FILE} ${WRKSRC}
	@${CP} -f ${AUTOMAKE_DIR}/${FILE} ${WRKSRCMASTER}
.endfor
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-lpthread||'

.include <bsd.port.mk>
