# Created by: Mathew Kanner <mat@hak.cnd.mcgill.ca>
# $FreeBSD$

PORTNAME=	tse3
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME:U}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIDI library

LICENSE=	GPLv2

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--without-doc-install
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

MAN1=		tse3play.1
MAN3=		tse3.3

OPTIONS_DEFINE=	ARTS DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MARTS}
LIB_DEPENDS+=	artsmidi:${PORTSDIR}/multimedia/kdemultimedia3
.else
CONFIGURE_ARGS+=	--without-aRts
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.jpeg ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/History ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/songs
	${INSTALL_DATA} ${WRKSRC}/demos/*.tse3 ${DOCSDIR}/songs
.endif

.include <bsd.port.mk>
