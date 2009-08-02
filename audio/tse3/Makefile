# New ports collection makefile for:    tse3
# Date created:				Wed Nov 12 14:10:12 PST 2003
# Whom:					Mathew Kanner <mat@hak.cnd.mcgill.ca>
#
# $FreeBSD$

PORTNAME=	tse3
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A MIDI library

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--without-doc-install
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
USE_LDCONFIG=	yes

MAN1=		tse3play.1
MAN3=		tse3.3

.include <bsd.port.pre.mk>

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsmidi:${PORTSDIR}/multimedia/kdemultimedia3
.else
CONFIGURE_ARGS+=	--without-aRts
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.jpeg ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/History ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/songs
	${INSTALL_DATA} ${WRKSRC}/demos/*.tse3 ${DOCSDIR}/songs
.endif

.include <bsd.port.post.mk>
