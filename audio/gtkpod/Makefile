# New ports collection makefile for:	gtkpod
# Date created: 			28 January 2003
# Whom: 				David Le Brun <david@dyn-ns.net>
#
# $FreeBSD$
#

PORTNAME=	gtkpod
PORTVERSION=	0.99.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GUI for Apple iPods using GTK2

LIB_DEPENDS=	id3tag.0:${PORTSDIR}/audio/libid3tag \
		gpod.302:${PORTSDIR}/audio/libgpod
RUN_DEPENDS=	mp3gain:${PORTSDIR}/audio/mp3gain \
		iconv:${PORTSDIR}/converters/libiconv

USE_X_PREFIX=	yes

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2
GNU_CONFIGURE=	yes

OPTIONS=	AAC	"Enable AAC support with MPEG4IP" off

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libmp4v2.so)
WITH_AAC=	YES
.endif

.if defined(WITH_AAC)
LIB_DEPENDS+=	mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2
.endif

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"

pre-configure:
# install locale correctly (share dir instead of lib dir)
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(libdir)/locale|(datadir)/locale|' \
		${WRKSRC}/po/Makefile.in.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODOandBUGS.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
