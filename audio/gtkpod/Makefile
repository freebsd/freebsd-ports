# New ports collection makefile for:	gtkpod
# Date created: 			28 January 2003
# Whom: 				David Le Brun <david@dyn-ns.net>
#
# $FreeBSD$
#

PORTNAME=	gtkpod
PORTVERSION=	0.80
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-2

MAINTAINER=	david@dyn-ns.net
COMMENT=	GUI for Apple iPods using GTK2

LIB_DEPENDS=	id3tag.2:${PORTSDIR}/audio/libid3tag
RUN_DEPENDS=	mp3gain:${PORTSDIR}/audio/mp3gain

USE_REINPLACE=	yes
USE_X_PREFIX=	yes

USE_GMAKE=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libmp4v2.so)
WITH_AAC=	YES
.endif

.if defined(WITH_AAC)
LIB_DEPENDS+=	mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip
.endif

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITH_AAC) && !defined(WITH_FAAD)
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "To enable AAC support with mpeg4ip define the WITH_AAC knob."
	@${ECHO_MSG}
.endif

pre-configure:
# install locale correctly (share dir instead of lib dir)
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(libdir)/locale|(datadir)/locale|' \
		${WRKSRC}/po/Makefile.in.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/TODOandBUGS.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
