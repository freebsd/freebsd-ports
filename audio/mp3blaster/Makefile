# New ports collection makefile for:	mp3blaster
# Date created:		5 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	mp3blaster
PORTVERSION=	3.1.3
CATEGORIES=	audio
MASTER_SITES=	http://www.stack.nl/~brama/mp3blaster/src/

MAINTAINER=	greid@FreeBSD.org

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cxxflags="${CXXFLAGS}" \
		--without-sidplay
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbisfile.3:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--without-oggvorbis
.endif

MAN1=		mp3blaster.1 nmixer.1 splay.1

.if !defined(WITHOUT_VORBIS)
pre-everything:
	@${ECHO_MSG}
	@${ECHO_MSG} "You can disable support for Ogg Vorbis by defining WITHOUT_VORBIS."
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
