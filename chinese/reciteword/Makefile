# Ports collection makefile for:	reciteword
# Date created:			1 November 2004
# Whom:				hamigua <hamigua@cuc.cn>
#
# $FreeBSD$
#

PORTNAME=	reciteword
PORTVERSION=	0.8.4
CATEGORIES=	chinese
MASTER_SITES=	SF:src \
		SF/${PORTNAME}/${PORTNAME}-books/${PORTVERSION}:books \
		SF/${PORTNAME}/${PORTNAME}-dicts/0.8.2:dicts
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.bz2:src \
		${PORTNAME}-books-${PORTVERSION}.tar.bz2:books \
		${PORTNAME}-dicts-0.8.2.tar.bz2:dicts

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Education software to help people to study English

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gtk20 esound
USE_GMAKE=	yes
CPPFLAGS+=	"-I${LOCALBASE}/include"

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README TODO readme.txt

OPTIONS=	RPTTS "With Real People TTS" off

.include <bsd.port.pre.mk>

.if defined(WITH_RPTTS)
RUN_DEPENDS+=	${LOCALBASE}/share/WyabdcRealPeopleTTS/a/a.wav:${PORTSDIR}/textproc/stardict2-rptts
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|' ${WRKSRC}/src/readword.cpp

post-install:
	@${MKDIR} ${DATADIR}
	(cd ${WRKDIR}/ && ${COPYTREE_SHARE} "books dicts" ${DATADIR} "! ( -type d -a -name CVS )")
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
