# New ports collection makefile for:	cplay
# Date created: 	1 November 2001
# Whom: 		Jochem Kossen
#
# $FreeBSD$
#

PORTNAME=	cplay
PORTVERSION=	1.45
CATEGORIES=	audio
MASTER_SITES=	http://www.tf.hut.fi/~flu/cplay/

MAINTAINER=	j.kossen@home.nl

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123

USE_GMAKE=	yes
USE_PYTHON=	yes
MAN1=		cplay.1

MAKE_ARGS+=	PREFIX="${PREFIX}"

.if defined(WITH_VORBIS)
RUN_DEPENDS+=	ogg123:${PORTSDIR}/audio/vorbis-tools
.endif

.if defined(WITH_MADPLAY)
RUN_DEPENDS+=	madplay:${PORTSDIR}/audio/mad
.endif

.if defined(WITH_MIKMOD)
RUN_DEPENDS+=	mikmod:${PORTSDIR}/audio/mikmod
.endif

.if defined(WITH_MPG321)
RUN_DEPENDS+=	mpg321:$(PORTSDIR)/audio/mpg321
.endif

.if defined(WITH_SPLAY)
RUN_DEPENDS+=	splay:${PORTSDIR}/audio/splay
.endif

pre-everything:
.if !defined(WITH_VORBIS) || !defined(WITH_MADPLAY) || !defined(WITH_MIKMOD) || defined(WITH_MPG321) || !defined(WITH_SPLAY)
	@${ECHO_MSG}
.if !defined(WITH_VORBIS)
	@${ECHO_MSG} "If you want to have OGG VORBIS support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_VORBIS=yes\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_MADPLAY)
	@${ECHO_MSG} "If you want to have MADPLAY support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_MADPLAY=yes\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_MIKMOD)
	@${ECHO_MSG} "If you want to have MIKMOD support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_MIKMOD=yes\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_MPG321)
	@${ECHO_MSG} "If you want to have MPG321 support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_MPG321=yes\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_SPLAY)
	@${ECHO_MSG} "If you want to have SPLAY support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_SPLAY=yes\""
	@${ECHO_MSG}
.endif
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cplay
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/cplay
	${INSTALL_MAN} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/cplay
	${INSTALL_MAN} ${WRKSRC}/TODO ${PREFIX}/share/doc/cplay
.endif

.include <bsd.port.mk>
