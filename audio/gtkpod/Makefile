# New ports collection makefile for:	gtkpod
# Date created: 			28 January 2003
# Whom: 				David Le Brun <david@dyn-ns.net>
#
# $FreeBSD$
#

PORTNAME=	gtkpod
PORTVERSION=	0.99.8
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GUI for Apple iPods using GTK2

LIB_DEPENDS=	id3tag.0:${PORTSDIR}/audio/libid3tag \
		gpod.1:${PORTSDIR}/audio/libgpod
RUN_DEPENDS=	mp3gain:${PORTSDIR}/audio/mp3gain \
		iconv:${PORTSDIR}/converters/libiconv

USE_X_PREFIX=	yes

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2
GNU_CONFIGURE=	yes

OPTIONS=	MPEG4IP	"Enable AAC and H.264 support with MPEG4IP" off

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libmp4v2.so)
WITH_MPEG4IP=	YES
.endif

.if defined(WITH_MPEG4IP)
LIB_DEPENDS+=	mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2
.endif

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"

pre-configure: .SILENT
# install locale correctly (share dir instead of lib dir)
	${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|' \
		${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|(libdir)/locale|(datadir)/locale|' \
		${WRKSRC}/po/Makefile.in.in
# work-around a segfault when attempting to delete track from iPod
	${REINPLACE_CMD} '83,85d' ${WRKSRC}/src/confirmation.c
# catch up with recent libgpod update to version 0.4.2
	${REINPLACE_CMD} -e 's|unk208|mediatype|g' ${WRKSRC}/src/file.c \
		${WRKSRC}/src/file_itunesdb.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODOandBUGS.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
